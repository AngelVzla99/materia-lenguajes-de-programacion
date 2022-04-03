#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define FOR(i,n,m) for(int i=n; i<m; i++)

using namespace std;

// tipo = 0 => operando perteneciente a { +, -, *, / }
// tipo = 1 => numero
// + , - | precedencia 0
// *, /  | precedencia 1 
struct token{
	int tipo; 
	int num;
	char op;
	int pre = -1;
	token(int t, int n, char o){
		tipo = t;
		num = n;
		op = o;
		pre = (op=='*'||op=='/');
	}
};

struct node{
	int tipo;
	char op;
	int num;
	int pre;
	node *L;
	node *R; 
	node( token t ){
		tipo = t.tipo;
		num = t.num;
		op = t.op;
		L = 0;
		R = 0;
		pre = t.pre;
	}
};

int mainHandler( string option, string ord, string exp );
