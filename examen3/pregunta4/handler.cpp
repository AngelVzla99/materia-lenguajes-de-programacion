#include "handler.hpp"

typedef pair<string,string> pss;
map<string, vector<pss>> h;

/*
Funcion para agregar una clase al arbol binario de busqueda 'h'
Complejidad: O( log(NumeroDeClases)*( ClasesDelPadre + ClasesNuevas ) )
Argumentos
* string name | Nombre de la clase a ser creada
* string super | Nombre de la clase padre ( cuando es igual a "" no tiene padre )
Return 
* 0 Si se logro agregar la clase con exito
* 2 Si el nombre de la clase ingresada ya fue declarado
* 3 Si el nombres de la clase super no existe
*/
int addClass( string name, string super, vector<string> resto ){
    int ans = 0;

    if( !h[name].empty() ) ans = 2;
    else if( super!="" && h[super].empty() ) ans = 3;
    else{
        vector<pss> tabla = h[super];

        // posicion de cada metodo en la tabla actual
        map<string,int> pos;
        FOR(i,0,tabla.size()) pos[tabla[i].second] = i+1;

        // si ya existe en la tabla, se cambia el nombre de la clase
        // sino se agrega un nuevo metodo
        for(string newMethod: resto){
            if( !pos[newMethod] ) tabla.push_back({name,newMethod});
            else tabla[pos[newMethod]-1].first = name;
        }

        h[name] = tabla;
    }
    return ans;
}

/*
Retorna la tabla de metodos virtuales correstpondiente 
al nombres ingresado por parametro. Se restorna en forma de lista
si la lista esta vacia el nombres no ha sido agregado
*/
vector<pss> getTable( string name ){
    return h[name];
} 

/*
Procedimiento para  eliminar todas las clases agregadas
*/
void cleanAllClass(){
    h.clear();
}