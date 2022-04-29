#include <iostream>
#include "modulo.h"

using namespace std;

int miVariable = 0;

int main() {
	
	my_class::increase();
	cout <<"epa"<< endl;
	my_class::increase();
	cout << my_class::getVar() << endl;
	cout <<"=> "<< miVariable << endl;
	
	return 0;
}
