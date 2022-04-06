#include "handler.hpp"

// ============ Auxiliar functions =================

bool validOperand( char c ){
	return c =='*' || c=='+' || c=='-' || c=='/';
}
bool validNum( char c ){
	return '0'<=c&&c<='9';
}
bool validChar( char c ){
	return c==' ' || c=='\t' || validNum(c) || validOperand(c);
}
bool isNum( string s ){
	for(char c: s) if( !validChar(c) ) return false;
	return true;
}

// ========== Read after here ==========

/*
Dada una lista de tokens esta funcion se encarga de crear
el arbol sintactico abstracto
Parametros
* vector<token> &tk | Lista de tokens
* int &i | posicion en la que se comienza a iterar en la lista tk
* PRE | indica si el orden en que se crea el arbol es prefija o postfija
Return
Regresa la raiz del AST
*/
node *makeTree( vector<token> &tk, int &i, bool PRE ){
	// si ocurre una llamada con i>tk.size() => Sobran tokens
	if( i>=tk.size() ){ i=tk.size()+5; return new node({-1,-1,' '}); }
	
	node *ans;
	if( tk[i].tipo ){
		ans = new node(tk[i++]);
	}else{
		ans = new node(tk[i++]);
		if(PRE){
			ans->L = makeTree(tk,i,PRE);
			ans->R = makeTree(tk,i,PRE);
		}else{
			ans->R = makeTree(tk,i,PRE);
			ans->L = makeTree(tk,i,PRE);
		}
	}
	return ans;
}

/*
Convierte el arbol sintactico abstracto en un string colocando
los parentesis de manera correcta
Parametros:
* node *nodo | Nodo actual a convertir a string
* node *fa=0 | padre del nodo actual
* rightChild=false | indica si el nodo actual es hijo derecho de su padre
return
Regresa el string compuesto por los simbolos del AST parentisado correctamente
*/
string toStrNode( node *nodo, node *fa=0, bool rightChild=false ){
	string ans = "";
	if(nodo>0){
		bool par = true;
		if( fa==0 || nodo->tipo || fa->pre<=nodo->pre ) par = false;
		if( fa!=0 && !nodo->tipo && fa->pre==nodo->pre && rightChild  ) par = true;
		
		if(par) ans+="(";
		ans += toStrNode(nodo->L,nodo,0);
		if(nodo->tipo) ans += to_string(nodo->num);
		else ans += nodo->op;
		ans += toStrNode(nodo->R,nodo,1);
		if(par) ans+=")";
	}
	return ans;
}

/*
Evalua un AST, donde las raices tienen que tener un numero
y el resto de nodos estan compuestos por uno de estos operadores
+, -, *, /
Argumentos:
* node *nodo | nodo actual a ser evaluado, tiene que ser un arbol valido
Return:
El valor de realizar todas las operaciones descritas por el AST
*/
int eval( node *nodo ){
	int ans;
	if( nodo->tipo ) ans = nodo->num;
	else{
		int valL = eval(nodo->L), valR = eval(nodo->R);
		switch(nodo->op) {
			case '+':
				ans = valL+valR;
				break;
			case '-':
				ans = valL-valR;
				break;
			case '*':
				ans = valL*valR;
				break;
			case '/':
				ans = valL/valR;
				break;
			default:
				break;
		}
	}
	return ans;
}

/*
Esta funcion se encarga de tokenizar una expresion donde cada simbolo
y numero estan separados por un espacio
Argumentos
* string exp | string con los posibles tokens separados por un espacio
Retrun 
Regresa una lista de tokens siendo un token la estructura definida en handler.hpp
*/
vector<token> tokenizer( string exp ){
	exp += " ";
    vector<token> ans;
	string str="";
	FOR(i,0,exp.size()){
		if( !validChar(exp[i]) ){
			ans.clear();
			return ans;
		}else if( exp[i]==' '|| exp[i]=='\t' ){
			// we found a token
			if( str.size() ){
				if( str.size()==1 && validOperand(str[0]) ){
					ans.push_back({0,-1, str[0]});
				}else if( isNum(str) ){
					ans.push_back({1, stoi(str), ' ' });
				}else{
					ans.clear();
					return ans;
				}
			}
			str = "";
		}else str += exp[i];
	}
	return ans;
}

/*
Esta funcion se encarga de manejar las 2 tipos de consultas
EVAL y MOSTRAR, tanto si son PRE como POST
Argumentos
* string option | option debe ser igual a EVAL o MOSTRAR
* string ord | ord debe ser igual a PRE o POST
* string exp | expresion a ser evaluada o mostrada
Return 
Posibles primera coordenada
 * 0 | Todo bien
 * 3 | Error de al lexicografico
 * 4 | Error en la exp
Si la primera coordenada es 0 => la segunda posee el strnig con
la respuesta a la consulta
*/
pair<int,string> mainHandler( string option, string ord, string exp ){
	pair<int,string> ans = {0,""};
	vector<token> tk = tokenizer(exp);
	if( tk.size()==0 ) ans = {3,""};
	else{
		int pos = 0;
		if( ord=="POST" ) reverse(tk.begin(),tk.end());
		node *n = makeTree(tk,pos,ord=="PRE");
		
		// si pos < tk.size() => No recorrio toda la lista
		// si pos = tk.size()+5 => Sobra un token
		if(pos!=tk.size()) ans = {4,""};
		else if( option=="EVAL" ){
			ans.second = to_string( eval(n) );
		}else{ 
			ans.second = toStrNode(n);
		}
	}
	return ans;
}

