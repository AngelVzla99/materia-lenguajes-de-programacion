#include "manejador.hpp"

/*
Esta funcion actua como un constructor del struct memManager
Dada la cantidad de bloques (len) crea un struct capaz de actuar
Como manejador de memoria usando las funciones reservar(), liberar() y show()
Parametros: 
* int len | Cantidad de bloques a reservar
*/
memManager *crearManejador( int len ){ 
	memManager *ans = (memManager*)malloc(sizeof(memManager));
	ans->len = len;
	ans->mem = vector<string>(len);
	FOR(i,0,len) ans->mem[i] = "";
	return ans;
}

/*
Esta funcion recibe un manejador de memoria y una variable y realiza
la operacion de reservar memoria (usando FIFO) 
Parametros:
* memManager *manager | puntero al struct manejador de memoria
* string name | nombre de la variable a reservar
* int len | Cantidad de bloques que ocupa 'name'
Return:
* 0 : Reserva exitosa
* 1 : nombre ya tiene mem reservada
* 2 : no hay un espacio libre contiguo suficientemente grande
 */
int reservar( memManager *manager, string name, int len ){
	int ans = 0;
	
	// Buscamos si la variable ya tiene memoria reservada
	FOR(i,0,manager->len) if(manager->mem[i]==name) ans = 1;
	if( ans==0 ){
		ans = 2;
		// Buscamos espacio dispoible para la variable
		FOR(i,len,manager->len+1){
			int valid = 1, l=i-len, r=i;
			FOR(j,l,r) if( manager->mem[j]!="" ) valid = 0;
			if( valid ){
				FOR(j,l,r) manager->mem[j] = name;
				ans = 0;
				break;
			}
		}
	}
	return ans;
}

/*
Esta funcion libera la memopria de una variable en un struct manager
Parametros:
* memManager *manager | Puntero al struct manejador de memoria
* string name | Nombre de la variable a liberar su memoria
Return
* 0 : Liberacion exitosa
* 1 : El nombre no tiene memoria reservada
 */
int liberar( memManager *manager, string name ){
	int ans = 1;
	// Buscamos si todas las ocurrencias de 'name' en la memoria
	FOR(i,0,manager->len){
		if( manager->mem[i]==name ){
			manager->mem[i]="";
			ans = 0;
		}
	}
	return ans;
}

/*
Esa funcion muestra de manera grafica que posiciones de la memoria estan
vacias y cuales estan ocupadas por una variable
Parametros:
*  memManager *manager | Manejador de memoria
*/
void show( memManager *manager ){
	FOR(i,0,manager->len){
		cout << "Bloque "<< i+1 << " | " << manager->mem[i] << endl;
	}
}
