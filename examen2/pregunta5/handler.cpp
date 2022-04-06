#include "handler.hpp"

// Mapeo del nombre de una variable a su tipo
map<string,tipo> mem; 
// Mapeo del nombre de una variable a bool para saber si ya existe
// una variable con este nombre
map<string,bool> toBe;

/*
returna true si la variable ya fue declarada
argumentos
* string name | nombre de la variabel
*/
bool haveBeenDeclare( string name ){
    return toBe[name];
}

/*
Funcion para agregar un tipo de datos atomico
Argumentos:
* string name | nombre del tipo
* representacion | tamano en bytes del tip
* alineacion | alineacion del tipo de dato
return 
* 0 si todo salio bien
* 1 si la variable ya habia sido declarada
*/
int addAtomic( string name, int representacion, int alineacion ){
    if( toBe[name] ) return 1;
    toBe[name] = true;

    // Se guarda el tipo de dato en meme 
    mem[name] = { name, representacion, alineacion, "atomic", name };
    return 0;
}

/*
Funcion para agregar una estructura de datos
Argumentos 
* string name | nombre del tipo
* vector<string> list | lista de tipos dentro del struct
Return
* 0 si todo salio bien
* 1 si la variable ya habia sido declarada antes
* 2 si una de las variables dentro del struct no han sido declaradas
*/
int addStruct( string name, vector<string> lista ){
    if( toBe[name] ) return 1;
    for(string s: lista) if( !toBe[s] ) return 2;
    toBe[name] = true;

    toBe[name] = true;
    int sum = 0;
    for(string s: lista) sum += mem[s].rep;
    mem[name] = { name, sum, -1, "struct", "", lista };  

    return 0;
}

/*
Funcion para agregar un alias a un arreglo de un cierto tipo
Argumentos
* string name | nombre del tipo 
* string t | nombre del tipo del arreglo
* int tamano | longitud del arreglo
Return
* 0 si todo salio bien
* 1 si el alias del arreglo ya existe
* 2 si no existe el tipo interno del arreglo
*/
int addArray( string name, string t, int tamano ){ 
    if( toBe[name] ) return 1;
    if( !toBe[t] ) return 2;
    toBe[name] = true;

    tipo subTipo = mem[t]; 
    mem[name] = { name, subTipo.rep*tamano, subTipo.ali, "array", t }; 
    return 0;
}

/*
Esta funcion dado un tipo de dato cacula la cantidad de bytes 
necesarios para almacenar este tipo de datos
Argumentos
* string nameT  | nombre del tipo de dato a consular
* int op        | Cual de los 4 tipos de datos se esta consultando
                  (leer resto de la funcion para saber mas)
* int &cu       | aca se guardara cuantos bytes son necesarios
Return 
* 0 | si todo salio bien
* 2 | si la variable no ha sido declarada
*/
int getEnd( string nameT, int op, int &cu ){
    if( !toBe[nameT] ) return 2;
    tipo t = mem[nameT];
    if( op==0 ){
        // • El lenguaje guarda registros y arreglos sin empaquetar.
        if( t.tipo=="atomic" ){
            while(cu%t.ali) cu++;
            cu += t.rep; 
        }else if( t.tipo=="array" ){
            tipo interno = mem[t.subTipo];
            FOR(i,0,t.rep/interno.rep){ 
                getEnd( interno.name, op, cu );
            }
        }else{
            for(string subT: t.listStruct){
                getEnd( mem[subT].name, op, cu ); 
            }
        }
    }else if( op==1 ){
        // • El lenguaje guarda registros empaquetados y arreglos sin empaquetar.
        if( t.tipo=="atomic" ){
            cu += t.rep; 
        }else if( t.tipo=="array" ){
            tipo interno = mem[t.subTipo];
            FOR(i,0,t.rep/interno.rep){ 
                while(cu%interno.ali) cu++; 
                cu += interno.rep; 
            } 
        }else{
            for(string subT: t.listStruct){
                getEnd( mem[subT].name, op, cu ); 
            }
        }
    }else if( op==2 ){
        // • El lenguaje guarda registros y arreglos empaquetados.
        cu = t.rep;
    }else if( op==3 ){
        // • El lenguaje guarda registros reordenando los campos de manera óptima (mini-
        //mizando la memoria, sin violar reglas de alineación) y arreglos sin empaquetar..
        if( t.tipo=="atomic" ){
            while(cu%t.ali) cu++;
            cu += t.rep; 
        }else if( t.tipo=="array" ){
            tipo interno = mem[t.subTipo];
            FOR(i,0,t.rep/interno.rep){ 
                getEnd( interno.name, op, cu );
            }
        }else{
            int len = t.listStruct.size();
            vector<int> nums;
            FOR(i,0,len) nums.push_back(i);
     
            int mi = 1e9, prev = cu;
            do{
                cu = prev; 
                for(int pos: nums){
                    string subT = t.listStruct[pos];
                    getEnd( mem[subT].name, op, cu );  
                }
                mi = min( mi, cu ); 
            }while( next_permutation(nums.begin(),nums.end()) ); 
            cu = mi;
        }
    }
    return 0;
}

/*
Funcion que se ayuda de la getEnd() para saber la cantidad de espacio
desoerdiciado para cada tipo dada una de las 4 opciones solicitadas en
el enunciado del problema
Argumetnos:
* string name   | nombre del tipo a consultar (el nombre debe estar definido)
* int op        | opcion entre 0 y 3 a consultar
Return
Cantidad de memoria desperdicidada 
*/
int getDesperdicio( string name, int op ){
    int pos = 0;
    int end = getEnd( name, op, pos );
    return pos - mem[name].rep; 
}