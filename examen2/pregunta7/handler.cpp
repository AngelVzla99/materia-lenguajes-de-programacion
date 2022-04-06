#include "handler.hpp"

// maxima cantidad de tumbas
const int MAXN = 10000;

int cuTumba = 1;
char *tumba[MAXN];
map<string,int> idTumba;

int reservar( string name, string val ){
    if( idTumba[name] ) return 2;
    idTumba[name] = cuTumba;

    int n = sz(val);
    char *a = (char*) malloc( (n+1)*sizeof(char) );
    strcpy(a,val.c_str());
    tumba[cuTumba++] = a;
    return 0;
}

int asignar( string nombre1, string nombre2 ){
    int id2 = idTumba[nombre2];
    if( !id2 ) return 4; 
    idTumba[nombre1] = id2; 
    return 0;
}

int liberar(string name){
    if( !idTumba[name] ) return 4;
    tumba[idTumba[name]] = 0;
    return 0;
}

pair<int,string> imprimir( string name ){ 
    if(!idTumba[name]) return {4,""};
    int id = idTumba[name];
    if( !tumba[id] ) return {3,""};

    string ans(tumba[id]); 
    return {0,ans}; 
}
