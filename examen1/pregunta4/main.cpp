#include <iostream>
#include "moduloVec.h"

using namespace vector;
using namespace std;

/*
Para probar el main se usa (archivo main.cpp)
$ make

Para probar los test cases (archivo test_unit.cpp)
$ make test_unit

Para probar la covertura del codigo con los testcases
$ make test_unit_coverage

Actualmente tiene una cobertura del 95.19%
*/

int main(){
	
	vec v1 = make_vec(1,1,1);
	vec v2 = make_vec(2,2,2);
	vec v3 = v1 * 20 + 0.5;
	cout <<"result = "<< v3 <<endl;
	cout <<"result = "<<vec_to_string(v3) << endl;
	
	return 0;
}
