#include <bits/stdc++.h>
#include "handler.hpp"

#define sz(x) (int)(x).size()
#define FOR(i,n,m) for(int i=n; i<m; i++)

using namespace std;

void error( int e ){
    if( e==1 ){
        cout <<"Error: <nombre> ya correspondea algún tipo creado en el programa.\n";
    }else if( e==2 ){
        cout <<"Error: El tipo utilizado no ha sido declarado.\n";
    }
}

void printDesperdicio( string name, int op ){
    if( op==0 ){
        cout <<"El lenguaje guarda registros y arreglos sin empaquetar.\n";
    }else if( op==1 ){
        cout <<"El lenguaje guarda registros empaquetados y arreglos sin empaquetar.\n";
    }else if( op==2 ){
        cout <<"El lenguaje guarda registros y arreglos empaquetados.\n";
    }else if( op==3 ){
        cout <<"El lenguaje guarda registros reordenando los campos de manera óptima (mini-mizando la memoria, sin violar reglas de alineación) y arreglos sin empaquetar..\n";
    }
    cout <<"Desperdicio = "<< getDesperdicio( name, op ) << endl;
}

int main(){
    while(true){
        cout <<"Seleccionar 1 de las siguientes opciones\n";
        cout <<"=> ATOMICO <nombre> <representación> <alineación>\n";
        cout <<"=> STRUCT <nombre> [<tipo>]\n";
        cout <<"=> ARREGLO <nombre> <tipo> <tamaño>\n";
        cout <<"=> DESCRIBIR <nombre>\n";
        cout <<"=> SALIR\n";
        
        int ans;
        string op; cin>>op;
        if( op=="ATOMICO" ){
            string name; int representacion, alineacion;
            cin>>name>>representacion>>alineacion;

            ans = addAtomic( name, representacion, alineacion );
        }else if( op=="STRUCT" ){
            string name, linea; cin>>name;
            getline(cin,linea);
            linea += " ";

            vector<string> lista;
            bool valid = true;
            string name2 = "";
            FOR(i,0,sz(linea)){
                if( linea[i]==' ' ){
                    if(sz(name2)){
                        // agg tipo al struct
                        lista.push_back(name2);
                    }
                    name2 = "";
                }else name2 += linea[i];
            }

            ans = addStruct( name, lista );
        }else if( op=="ARREGLO" ){
            string name, tipo; int tamano;
            cin>>name>>tipo>>tamano;

            ans = addArray( name, tipo, tamano );
        }else if( op=="DESCRIBIR" ){
            string name; cin>>name;
            
            int pos = 0;
            ans = getEnd(name, 2, pos);
            if(!ans) FOR(i,0,4) printDesperdicio( name, i );
        }else if( op=="SALIR" ){
            break;
        }

        if(ans) error(ans);
        cout << '\n';
    }    

    return 0;
}
