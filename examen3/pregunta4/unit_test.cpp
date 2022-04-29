#include "acutest.hpp"
#include "handler.hpp"

string listToString( vector<pair<string,string>> L ){
    string ans = "<< ";
    FOR(i,0,L.size()){
        ans += "<" + L[i].first + " | "+  L[i].second + ">, ";
    }
    ans += " >>";
    return ans;
}

string listToString( vector<string> L ){
    string ans = "<< ";
    FOR(i,0,L.size()){
        ans += "<" + L[i] + ">, ";
    }
    ans += " >>";
    return ans;
}

void test_PDF(void){
    // Agregamos a la estructura
	TEST_CHECK_(addClass("A","",{"f","g"})==(0), "Caso 1");
    TEST_CHECK_(addClass("B","A",{"f","h"})==(0), "Caso 2");

    // mostramos la tabla
    vector<pair<string,string>> ans = { {"B","f"}, {"A","g"}, {"B","h"} };
    TEST_CHECK_(getTable("B")==(ans), "Caso 2");

    // limpiamos la tabla para evitar conflictos entre testcases
    cleanAllClass();
}

void test_exahustivo(void){
    // Numero de clases
    int N = 500;

    // Nombre de cada clase
    vector<string> name, notName;
    FOR(i,0,N){
        name.push_back( to_string(i) );
        notName.push_back( to_string(N+i) );
    }

    // metodos de las clases
    vector<vector<string>> methods;
    methods.push_back( {"f"} );
    FOR(i,1,N){
        string method = "g" + to_string(i);
        string method2 = methods.back()[0];
        methods.push_back( { method, method2 } ); 
    }

    // Agregamos a la estructura
    // Este test consiste en que cada nueva clase tiene todos los metodos de las anteriores
    // pero sobreescribe el metodo recien creado de la clase i-1 y crea un nuevo metodo
	TEST_CHECK_(addClass(name[0],"",methods[0])==(0), "Caso Base");
    FOR(i,1,N){
        TEST_CHECK_(addClass(name[i],name[i-1],methods[i])==(0), "Caso i-th");
    } 

    // Verificamos las tablas
    vector<pair<string,string>> ans = { {name[0], "f"} };
    TEST_CHECK_(getTable(name[0])==(ans), "Save Caso base");
    FOR(i,1,N){
        string method = "g" + to_string(i);
        int len = ans.size();
        // se le suma 1 al propietario de este metodo
        ans[len-1].first = to_string(i);
        // se agrega el nuevo metodo
        ans.push_back({to_string(i),method});
        TEST_CHECK_(getTable(name[i])==(ans), "Save Caso i-th %s %s", listToString(getTable(name[i])), listToString(ans)  );
    }

    // Nombres no agregados
    ans.clear();
    for(string nombre: notName){ 
        TEST_CHECK_(getTable(nombre)==(ans), "Save Nombre no existente"  );
    }

    // nombre ya existente
    FOR(i,0,N){
        TEST_CHECK_(addClass(name[i],name[i],methods[i])==(2), "Caso nombre ya resservado");
    }

    // nombre no existente de super clase
    FOR(i,0,N){
        TEST_CHECK_(addClass(notName[i],notName[i],methods[i])==(3  ), "Caso nombre ya resservado");
    }

    // limpiamos la tabla para evitar conflictos entre testcases
    cleanAllClass();
}

TEST_LIST = {
	{"Test que sale de eje,plo", test_PDF},
    {"Test exahustivo", test_exahustivo},
	{0}
};
