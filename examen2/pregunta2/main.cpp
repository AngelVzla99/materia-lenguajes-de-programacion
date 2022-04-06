#include <bits/stdc++.h>
#include "handler.hpp"

#define FOR(i,n,m) for(int i=n; i<m; i++)

using namespace std;

/* 
Funcion para  leer una linea de caracteres sin usar cin>>
longitud del buffer = 10000
* return: La linea ingresada poe el usuario
*/
string readLine(){
	char *buffer;
    size_t bufsize = 10000;
    size_t characters;

	// se reserva memoria
    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL){
        perror("Unable to allocate buffer");
        exit(1);
    }

    characters = getline(&buffer,&bufsize,stdin);
    
	// Se para el arreglo de caracterse a string 
    string ans = "";
    int n = strlen(buffer);
    FOR(i,1,n-1) ans += buffer[i];
	return ans;
};

/*
En esta funcion se encuentra el menu principal que se usa en
el programa, tras pedir una accion al usuario se hacen las correspondientes
llamadas a las funciones en handler.cpp 
*/
int main(){
		
	while(true){
		cout <<"\nSeleccionar una de las siguientes opciones:\n";
		cout <<"=> EVAL <orden> <expr>\n";
		cout <<"=> MOSTRAR <orden> <expr>\n";
		cout <<"=> SALIR\n";
		string op; cin>>op;
		
		int ans =  0;
		if( op=="EVAL" || op=="MOSTRAR" ){
			string ord, exp; cin>>ord;
			exp = readLine();
			
			if( ord!="PRE" && ord!="POST" ) ans = 2;
			else{
				// Esto es un par donde la primera coordenada indica si 
				// hubo un error y cual la segunda dice, si no hubo error, la respuesta 
				pair<int,string> temp = mainHandler( op, ord, exp );
				ans = temp.first;
				if(!ans) cout << temp.second << '\n';
			}
		}else if( op=="SALIR" ){ 
			break;
		}else{
			ans = 1;
		}
		
		// Mensajes de error
		if( ans==1 ) cout <<"Opcion invalida\n"; 
		else if( ans==2 ) cout <<"<orden> solo puede ser PRE o POST\n";
		else if( ans==3 ) cout <<"Error lexicografico en la expresion\n";
		else if( ans==4 ) cout <<"Expresion invalida\n";
	}
	
    return 0;
}

