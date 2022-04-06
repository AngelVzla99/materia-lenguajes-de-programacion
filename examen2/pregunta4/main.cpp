#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>
#include "funcs.hpp"
#include <bits/stdc++.h>


#define FOR(i,n,m) for(int i=n; i<m; i++)
typedef long long ll;

using namespace std;

/*
Esta funcion calcula el tiempo en que tarda alguna de las funciones
que se encuetran en funcs.cpp en responder y lo imprime por stardar output
*/
int main(int argc, char *argv[] ){
	
	if( argc==2 ){
		string op = "";
		FOR(i,0,strlen(argv[1])) op+=argv[1][i];
		
		ll n;
		double duration;
		if( op=="-d" || op=="-c" || op=="-i" ){
			while( cin>>n ){
				// inicio del tiempo del programa
				auto begin = chrono::high_resolution_clock::now();
				
				// si pusiera (else if) los tiempos no serian comparables
				ll valor;
				if( op=="-d" ) valor = fibo1(n);
				if( op=="-c" ) valor = fibo2(n);
				if( op=="-i" ) valor = fibo3(n);
				
				// duracion del tiempo del programa
				auto end = std::chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
				cout <<  duration << '\n';
			}
		}else{
			// Eror de parametro del programa
			cout <<"Error: unicas opciones :\n";
			cout <<"-d (directo)\n";
			cout <<"-c (recursion de cola)\n";
			cout <<"-i (iterativo)\n";
		}
	}else{
		cout <<"Error: Numero de parametro invalido\n";
	}
	
    return 0;
}

