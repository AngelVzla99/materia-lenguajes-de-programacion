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

node *makeTree( vector<token> &tk, int &i, bool PRE ){
	// si ocurre una llamada con i>tk.size() => Sobran tokens
	if( i>=tk.size() ){ i=tk.size()+5; return new node({-1,-1,' '}); }
	
	node *ans;
	if( tk[i].tipo==1 ){
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
 * If the list is empty, it's an error
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
 * 0 | Todo bien
 * 3 | Eror de al lexicografico
 * 4 | Error en la exp
*/
int mainHandler( string option, string ord, string exp ){
	int ans = 0;
	vector<token> tk = tokenizer(exp);
	if( tk.size()==0 ) ans = 3;
	else{
		int pos = 0;
		if( ord=="POST" ) reverse(tk.begin(),tk.end());
		node *n = makeTree(tk,pos,ord=="PRE");
		
		// si pos < tk.size() => No recorrio toda la lista
		// si pos = tk.size()+5 => Sobra un token
		if(pos!=tk.size()) ans = 4;
		else if( option=="EVAL" ){
			cout << eval(n) << '\n';
		}else{ 
			cout << toStrNode(n) << '\n';
		}
	}
	return ans;
}

/*

MOSTRAR PRE - 2 + 1 3
// 2 - (1+3)

MOSTRAR POST 1 2 3 + -
// 1-(2+3)

MOSTRAR POST 2 3 4 * +
// 2+3*4

MOSTRAR PRE / 1 / 2 3

*/
