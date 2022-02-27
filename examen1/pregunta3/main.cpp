#include <iostream>
#include <string>
#include <cstring>
#include "manejador.hpp"

typedef long long ll;

using namespace std;

/*

Para probar el main se usa (archivo main.cpp)
$ make

Para probar los test cases (archivo test_unit.cpp)
$ make test_unit

Para probar la covertura del codigo con los testcases
$ make test_unit_coverage

Actualmente tiene una cobertura del 86.67%
*/

int main( int argc, char *argv[] ){
	
	if( argc!=2 ){
		cout <<"Error"<<endl;
		cout <<"Al llamar al programa se debe inficar el numero ";
		cout <<"de bloques a reservar, poe parametro"<<endl;
	}else{
		int len = stoi(argv[1]);
		memManager *manager = crearManejador(len);
		while(true){
			cout <<"Selesccionar 1 de las opciones:"<<endl;
			cout <<"=> RESERVAR <NOMBRE> <CANTIDAD>" <<endl;
			cout <<"=> LIBERAR <NOMBRE>"<<endl;
			cout <<"=> MOSTRAR"<<endl;
			cout <<"=> SALIR"<<endl;
			string op; cin>>op;
			
			if( op=="RESERVAR" ){
				string nombre; int cantidad;
				cin>>nombre>>cantidad;
				
				int ans = reservar(manager,nombre,cantidad);
				if( ans==0 ){
					cout <<"Reservacion exitosa !!"<< endl;
				}else if( ans==1 ){
					cout <<"Error\nEl nombre "<< nombre <<" ya tienen memoria reservada "<<endl; 
				}else{
					cout <<"Error\nNo hay un espacio libre contiguo suficientemente grande como para satisfacer la petición"<< endl;
				}
			}else if( op=="LIBERAR" ){ 
				string nombre; cin>> nombre;
				int ans = liberar(manager,nombre);
				
				if( ans==0 ){
					cout <<"Liberacion de memoria exitosa"<< endl;
				}else{
					cout <<"Error\nEl nombre no tiene memoria reservada"<< endl;
				}
			}else if( op=="MOSTRAR" ){
				show( manager );
			}else if( op=="SALIR" ){
				break;
			}else{
				cout <<"Error\nComando invalido, las unicas opciones validas son: ";
				cout <<"RESERVAR, LIBERAR, MOSTRAR, SALIR"<<endl;
			}
			cout << endl;
		}
	}
	
	return 0;
}
