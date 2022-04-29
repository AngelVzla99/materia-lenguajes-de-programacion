#include "handler.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <utility>

#define FOR(i,n,m) for(int i=n; i<m; i++)
typedef long long ll;

using namespace std;

/*
Funcion para leer una linea de caracteres ingresados por el usuario
Return
* La linea ingresada por el usuario
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
    
	// Convertir arreglo de caracterse a string 
    string ans = "";
    int n = strlen(buffer);
    FOR(i,1,n-1) ans += buffer[i];
	ans += " ";

	return ans;
};

/*
Esta funcion se encarga de hacer split s un string separando por
un caracter 'c'
Argumentos:
* string linea |  string a ser separado
* char c | caracter para serparar el string
Return
* Regresa una lista de los strings tras hacer split de c
*/
vector<string> split( string linea, char c ){
	vector<string> ans;
	string temp = "";
	FOR(i,0,linea.size()){
		if( linea[i]==c ){
			if( temp.size() ){
				ans.push_back(temp);
				temp = "";
			}
		}else{
			temp += linea[i];
		}
	}
	return ans;
}

/*
Funcion encargada de imprimir los diferentes errores que le pueden
ocurrir al usuario
Argumentos
* int i | Numero del error
Side Effect
* Imprime el error
*/
void error( int i ){
	cout <<"Error: ";
	if( i==1 ) cout << "Numero de parametros invalidos\n";
	else if( i==2 ) cout <<"El nombre de la clase ingresada ya fue declarado\n";
	else if( i==3 ) cout <<"El nombres de la clase super no existe\n";
	else if( i==4 ) cout <<"La tabla solicitada no existe\n";
}

int main(){

	while(true){
		// Menu para el usuario	
		cout << "Seleccione alguna de las siguientes opciones\n";
		cout <<"1) CLASS <tipo> [<nombre>]\n";
		cout <<"2) DESCRIBIR <nombre>\n";
		cout <<"3) SALIR\n";
		string op; cin>>op;

		int ans = 0;
		if( op=="CLASS" ){
			// Pedimos una linea al usuario y la separamos por espacios
			vector<string> tks = split( readLine(), ' ' );

			if( tks.size()<2 ) ans = 1;
			if( tks[1]==":" && tks.size()<3 ) ans = 1;
			else{
				string name = tks[0];
				string super = (tks[1]==":"?tks[2]:"");
				vector<string> resto;
				FOR(i,1+2*bool(tks[1]==":"),tks.size()) 
					resto.push_back( tks[i] );

				// Intentamos agregar la clase
				ans = addClass( name, super, resto );
				if(!ans) cout <<"Clase creada exitosamente !!\n";
			}
		}else if( op=="DESCRIBIR" ){
			// Pedimos el nombre de la tabla e imprimimos su correspondiente tabla de metodos virtuales
			string name; cin>>name;
			vector<pair<string,string>> tabla = getTable( name );
			if( tabla.empty() ) ans = 4;
			
			// Imprimimos la lista en el formato requerido
			for( auto e: tabla ){
				cout << e.second << " -> " << e.first << " :: " << e.second << '\n';
			}
		}else if( op=="SALIR" ){
			break;
		}
		if(ans) error(ans);
		cout << "\n\n";
	}

    return 0;
}

