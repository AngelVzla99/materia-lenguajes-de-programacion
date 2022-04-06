#include <bits/stdc++.h>
#include "handler.hpp"

#define FOR(i,n,m) for(int i=n; i<m; i++)

using namespace std;

string readLine(){
	char *buffer;
    size_t bufsize = 10000;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL){
        perror("Unable to allocate buffer");
        exit(1);
    }

    //printf("Type something: ");
    characters = getline(&buffer,&bufsize,stdin);
    //printf("%zu characters were read.\n",characters);
    //printf("You typed: '%s'\n",buffer);
    
    string ans = "";
    int n = strlen(buffer);
    FOR(i,1,n-1) ans += buffer[i];
	return ans;
};

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
				pair<int,string> temp = mainHandler( op, ord, exp );
				ans = temp.first;
				if(!ans) cout << temp.second << '\n';
			}
		}else if( op=="SALIR" ){ 
			break;
		}else{
			ans = 1;
		}
		
		if( ans==1 ) cout <<"Opcion invalida\n"; 
		else if( ans==2 ) cout <<"<orden> solo puede ser PRE o POST\n";
		else if( ans==3 ) cout <<"Error lexicografico en la expresion\n";
		else if( ans==4 ) cout <<"Expresion invalida\n";
	}
	
    return 0;
}

