#include "handler.hpp"

map<string,tipo> mem; 
map<string,bool> toBe;

bool haveBeenDeclare( string name ){
    return toBe[name];
}

int addAtomic( string name, int representacion, int alineacion ){
    if( toBe[name] ) return 1;
    toBe[name] = true;

    mem[name] = { name, representacion, alineacion, "atomic", name };
    return 0;
}

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

int addArray( string name, string t, int tamano ){ 
    if( toBe[name] ) return 1;
    if( !toBe[t] ) return 2;
    toBe[name] = true;

    tipo subTipo = mem[t]; 
    mem[name] = { name, subTipo.rep*tamano, subTipo.ali, "array", t }; 
    return 0;
}

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

int getDesperdicio( string name, int op ){
    int pos = 0;
    int end = getEnd( name, op, pos );
    return pos - mem[name].rep; 
}