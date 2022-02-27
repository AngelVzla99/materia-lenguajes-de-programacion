#include <iostream>
#include <string>
#include "acutest.hpp"
//#include "moduloVec.h"

#define FOR(i,n,m) for(int i=n; i<m; i++)

using namespace std;

/*
 Tuve que copiar y pegar el codigo del modulo moduloVec.h porque gcov
 no me dejaba saber la cobertura con un archivo.h (tambien probe
 poniendolo en un cpp y daba mas problemas) sin embargo al copiar y 
 pegarlo funciono adecuadamente y da como resultado 95.19% de cobertura
 para verlo solo hay que hacer:
 
 $ make test_unit_coverage
 
 Al comienzo aparece el resultado de los testCases y luego el porcentaje
 de cobertura
 */
namespace vector{
	struct vec{
		double a, b, c;
		
		// suma de dos vectores
		vec operator+ ( vec const &v2 ){
			vec ans;
			ans.a = a + v2.a;
			ans.b = b + v2.b;
			ans.c = c + v2.c;
			return ans;
		}
		
		// resta de dos vectores
		vec operator- ( vec const &v2 ){
			vec ans;
			ans.a = a - v2.a;
			ans.b = b - v2.b;
			ans.c = c - v2.c;
			return ans;
		}
		
		// producto cruz de dos vectores
		vec operator* ( vec const &v2 ){
			vec ans;
			ans.a = b*v2.c - c*v2.b;
			ans.b = c*v2.a - a*v2.c;
			ans.c = a*v2.b - b*v2.a;
			return ans;
		}
		
		// producto punto 
		double operator% ( vec const &v2 ){
			double ans = a*v2.a + b*v2.b + c*v2.c;
			return ans;
		}
		
		// Sumar constante a vector
		vec operator+ ( double const &val ){
			vec ans;
			ans.a = a + val;
			ans.b = b + val;
			ans.c = c + val;
			return ans;
		}
		
		// Sumar constante a vector
		vec operator- ( double const &val ){
			vec ans;
			ans.a = a - val;
			ans.b = b - val;
			ans.c = c - val;
			return ans;
		}
		
		// Sumar constante a vector
		vec operator* ( double const &val ){
			vec ans;
			ans.a = a * val;
			ans.b = b * val;
			ans.c = c * val;
			return ans;
		}
		
		// se define el operador igual
		bool operator==( vec const &v2 ){
			return a==v2.a && b==v2.b && c==v2.c;
		}
		
		// se define el output con cout
		friend ostream &operator<<( ostream &out, vec const &v ){ 
			out <<"("<< v.a << " "<<v.b<< " "<<v.c<<")";
			return out;
		}
	};
	
	vec make_vec(double a, double b, double c){
		return {a,b,c};
	}
	
	string vec_to_string( vec v ){
		string ans = to_string(v.a) + " ";
		ans += to_string(v.b) + " ";
		ans += to_string(v.c);
		return ans;
	}
}

using namespace vector;

void test_suma(void){
	vec v1 = make_vec(1,1,1);
	vec v2 = make_vec(2,2,2);
	vec v3 = make_vec(3,3,3);
	TEST_CHECK_((v1+v2)==(v3), "Caso1");
	
	v1 = make_vec(1,2,3);
	v2 = make_vec(3,4,5);
	v3 = make_vec(4,6,8);
	TEST_CHECK_((v1+v2)==(v3), "Caso2");
	
	v1 = make_vec(100,200,300);
	v2 = make_vec(3,4,5);
	v3 = make_vec(103,204,305);
	TEST_CHECK_((v1+v2)==(v3), "Caso3");
}

void test_resta(void){
	vec v1 = make_vec(1,1,1);
	vec v2 = make_vec(2,2,2);
	vec v3 = make_vec(-1,-1,-1);
	TEST_CHECK_((v1-v2)==(v3), "Caso1");
	
	v1 = make_vec(1,2,3);
	v2 = make_vec(3,4,5);
	v3 = make_vec(-2,-2,-2);
	TEST_CHECK_((v1-v2)==(v3), "Caso2");
	
	v1 = make_vec(200,300,400);
	v2 = make_vec(100,200,300);
	v3 = make_vec(100,100,100);
	TEST_CHECK_((v1-v2)==(v3), "Caso3");
}

void test_cross_product(void){
	vec v1 = make_vec(2,4,-5);
	vec v2 = make_vec(-3,-2,1);
	vec v3 = make_vec(-6,13,8);
	TEST_CHECK_((v1*v2)==(v3), "Caso1");
	
	v1 = make_vec(1,-3,4);
	v2 = make_vec(-2,1,1);
	v3 = make_vec(-7,-9,-5);
	TEST_CHECK_((v1*v2)==(v3), "Caso2");
	
	v1 = make_vec(2,0,-7);
	v2 = make_vec(-3,-4,0);
	v3 = make_vec(-28,21,-8);
	TEST_CHECK_((v1*v2)==(v3), "Caso2");
}

void test_dot_product(void){
	vec v1 = make_vec(2,4,-5);
	vec v2 = make_vec(-3,-2,1);
	TEST_CHECK_((v1%v2)==(-19), "Caso1");
	
	v1 = make_vec(1,-3,4);
	v2 = make_vec(-2,1,1);
	TEST_CHECK_((v1%v2)==(-1), "Caso2");
	
	v1 = make_vec(1,-3,10);
	v2 = make_vec(-2,1,10);
	TEST_CHECK_((v1%v2)==(95), "Caso2");
}

void test_consts(void){
	vec v1 = make_vec(1,1,1);
	vec v2 = make_vec(2,2,2);
	vec v3 = make_vec(10,10,10);
	TEST_CHECK_(( (v1+v2)+7 )==(v3), "Caso1");
	
	v1 = make_vec(1,1,1);
	v3 = make_vec(10.0,10.0,10.0);
	TEST_CHECK_(( v1*3.0 + 7.0 )==(v3), "Caso2");
	
	v1 = make_vec(1,1,1);
	v2 = make_vec(1,-3,4);
	v3 = make_vec(-2,1,1);
	vec v4 = make_vec(-1.0,-1.0,-1.0);
	TEST_CHECK_(( v1 * (v2%v3) )==(v4), "Caso3");
}

TEST_LIST = {
	{"Test de suma de vectores", test_suma},
	{"Test de resta de vectores", test_resta},
	{"Test de producto cruz de vectores", test_cross_product},
	{"Test de producto punto", test_dot_product},
	{"Test de constantes", test_consts},
	{0}
};

