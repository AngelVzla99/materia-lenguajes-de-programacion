#include "handler.hpp"

// maxima cantidad de tumbas
const int MAXN = 10000;

// tumba actual disponible
int cuTumba = 1;
// puntero de la tumba i-esima
char *tumba[MAXN];
// posicion en tumba de un string (nombre de variable)
map<string,int> idTumba;

/*
Esta funcion se encarga de reservar memoria para un puntero 
y asignarle un valor
Argumentos
* string name   | nombre del puntero a reservar memoria
* string val    | valor con el que se inicializa
Return
* 0 si todo salio bien
* 2 si ya existe un puntero con este nombre
*/
int reservar( string name, string val ){
    if( idTumba[name] ) return 2;
    idTumba[name] = cuTumba;

    int n = sz(val);
    char *a = (char*) malloc( (n+1)*sizeof(char) );
    strcpy(a,val.c_str());
    tumba[cuTumba++] = a;
    return 0;
}

/*
Funcion para para x = y en C, asignacion entre dos punteros
Argumentos:
* string nombre1    | nombre del puntero de la izquierda
* string nombre2    | nombre del puntero de la derecha
Return
* 0 si todo salio bien
* 4 si el puntero de la derehca no ha sido definido
*/
int asignar( string nombre1, string nombre2 ){
    int id2 = idTumba[nombre2];
    if( !id2 ) return 4; 
    idTumba[nombre1] = id2; 
    return 0;
}

/*
Funcion para liberar el espacio en memoria de una variable
implementado como tumbas
Argumentos
* string name | nombre del puntero a ser liberado 
Return 
* 0 si todo salio bien
* 4 si no hay puntero con ese nombre
*/
int liberar(string name){
    if( !idTumba[name] ) return 4;
    free( tumba[idTumba[name]] );
    tumba[idTumba[name]] = 0;
    return 0;
}

/*
Retirna una tumpla con el string que tiene asignado el puntero
Argumentos
* string name | nombre del puntero
Return
Primer valor de la tupla
* 0 si todo aslio bien
* 4 si no hay puntero con ese nombre
* 3 si la memoria correspondiete fue liberada
*/
pair<int,string> imprimir( string name ){ 
    if(!idTumba[name]) return {4,""};
    int id = idTumba[name];
    if( !tumba[id] ) return {3,""};

    string ans(tumba[id]); 
    return {0,ans}; 
}
