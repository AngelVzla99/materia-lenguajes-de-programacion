#include "acutest.hpp"
#include "manejador.hpp"

void test_all(void){
	int len = 10;
	memManager *manager = crearManejador(len);
	
	// llenar la memoria de datos (dejando 1 bloque libre)
	vector<string> variables;
	FOR(i,0,len-1){
		string name = "var"+to_string(i+1);
		variables.push_back(name);
		TEST_CHECK_(reservar(manager,name,1)==(0), "Caso1");
	}
	
	//intentan reservar con el mismo nombre
	for(auto name: variables){
		TEST_CHECK_(reservar(manager,name,1)==(1), "Caso2");
	}
	
	// intentan reservar una variable que ocupe 2 bloques
	string name = "superVar";
	TEST_CHECK_(reservar(manager,name,2)==(2), "Caso3");
	
	// liberamos cada variable creada
	for(auto name: variables){
		TEST_CHECK_(liberar(manager,name)==(0), "Caso4");
	}
	
	// intentamos volver a liberar
	for(auto name: variables){
		TEST_CHECK_(liberar(manager,name)==(1), "Caso5");
	}
}

TEST_LIST = {
	{"Test con variables y diferentes operaciones", test_all},
	{0}
};
