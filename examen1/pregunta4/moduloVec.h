#include <iostream>
#include <string>

using namespace std;

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
