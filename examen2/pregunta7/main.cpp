#include <bits/stdc++.h>
#include "handler.hpp"

#define sz(x) (int)(x).size()
#define FOR(i,n,m) for(int i=n; i<m; i++)

/*
Funcion para imprimir un error especifico en el programa
Argumento
* e numero del error
*/
void error(int e){
    cout <<"Error: ";
    if(e==1){
        cout <<"Opcion invalida\n";
    }else if(e==2){
        cout <<"Ya existe un puntero con este nombre\n";
    }else if(e==3){
        cout <<"La memoria de esta variable fue liberada\n";
    }else if(e==4){
        cout <<"No existe un puntero con este nombre\n";
    }
}

/*
Funcion para mostrar al usuario del programa un menu interactivo
este programa es una implementacion del descrito en la pregunta 7
del examen 2 de lenguajes de programcion. La funcion tras verificar
que el input es correcto utiliza las funciones que se encunetran
en el archivo handler.cpp
*/
int main(){

    cout <<"Para este programa se implemento en manejador con lapidas\n";

    while(true){
        cout <<"Seleccionar una de las siguientes opciones\n";
        cout <<"=> RESERVAR <nombre> <valor>\n";
        cout <<"=> ASIGNAR <nombre1> <nombre2>\n";
        cout <<"=> LIBERAR <nombre>\n";
        cout <<"=> IMPRIMIR <nombre>\n";
        cout <<"=> SALIR\n";
        string op; cin>>op;

        int ans;
        if(op=="RESERVAR"){
            string nombre, val; cin>>nombre>>val;
            ans = reservar(nombre,val); 
            if(!ans) cout <<"Se reservo mememoria para '"<<nombre<<"'\n";
        }else if(op=="ASIGNAR"){
            string s1, s2; cin>>s1>>s2;
            ans = asignar(s1,s2);
            if(!ans) cout <<"Se le asigno un '"<<s2<<"' a '"<<s1 <<'\n';
        }else if(op=="LIBERAR"){
            string name; cin>>name;
            ans = liberar(name);
            if(!ans) cout <<"Se libero '"<<name<<"'\n";
        }else if(op=="IMPRIMIR"){
            string name; cin>>name;
            pair<int,string> temp = imprimir(name);
            ans = temp.first;
            if(!ans) cout << temp.second << '\n';
        }else if(op=="SALIR"){
            break;
        }else{
            ans = 1;
        }
        if(ans) error(ans);
        cout << '\n';
    }    

    return 0;
}