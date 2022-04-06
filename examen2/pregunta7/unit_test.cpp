#include <bits/stdc++.h>
#include "acutest.hpp"
#include "handler.hpp"

void test_all(void){

    int n = 100; // no puede ser mayor a MAXN en handler.cpp
    vector<pair<string,string>> varName;
    FOR(i,0,n){
        string name = "var"+to_string(i), val = "val"+to_string(i);
        varName.push_back({ name, val }); 
    }
    
    // probar agregar punteros
    for(auto p: varName){
        string name = p.first, val = p.second;
        TEST_CHECK_(reservar(name,val)==(0), "Caso1"); 
    }
    
    // verificar valores
    for(auto p: varName){
        string name = p.first, val = p.second;
        pair<int,string> ans = imprimir( name );
        TEST_CHECK_((ans.first)==(0), "Caso2.1");
        TEST_CHECK_(ans.second==val, "Caso2.2 |%s| difertente de |%s| | ",ans.second.c_str(), val.c_str()); 
    }

    // => la mitad apunta al primero
    string name1 = varName[0].first, val1 = varName[0].second;
    FOR(i,1,n/2){
        string name = varName[i].first, val = varName[i].second;
        TEST_CHECK_(( asignar(name,name1) )==(0), "Caso3 asignacion");
    }
    // => Deben tener el valor de valName[0]
    FOR(i,1,n/2){
        string name = varName[i].first, val = varName[i].second;
        pair<int,string> ans = imprimir( name );
        TEST_CHECK_((ans.first)==(0), "Caso4.1.1 comportamiento de puntero"); 
        TEST_CHECK_((ans.second)==(val1), "Caso4.1.2 comportamiento de puntero"); 
    }

    // => liberamos a valName[1]
    TEST_CHECK_( ( liberar(varName[1].first) )==(0), "Caso4.2 liberar puntero"); 
    FOR(i,0,n/2){
        string name = varName[i].first, val = varName[i].second;
        pair<int,string> ans = imprimir( name ), expect = {3,""};
        TEST_CHECK_( ( imprimir(name) )==(expect), "Caso4.2 liberar puntero"); 
    }
    
    // variables que no estan  
    vector<string> varNameNotExist;
    FOR(i,n+1,2*n) varNameNotExist.push_back( "var"+to_string(i) );
    for(string name: varNameNotExist){
        TEST_CHECK_( ( liberar(name) )==(4), "Caso5 liberar no existente"); 
        TEST_CHECK_( ( asignar(name1,name) )==(4), "Caso5 asignar no existente"); 
    }
}

TEST_LIST = {
	{"Test completo", test_all},
	{0}
};
