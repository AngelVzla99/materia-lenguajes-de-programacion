#include "acutest.hpp"
#include "handler.hpp"

void test_all(void){
    // agregar tipos atomicos
	TEST_CHECK_(addAtomic("bool",1,2)==(0), "Caso 1");
    TEST_CHECK_(addAtomic("char",1,2)==(0), "Caso 1");
    TEST_CHECK_(addAtomic("int",4,4)==(0), "Caso 1");
    TEST_CHECK_(addAtomic("double",8,8)==(0), "Caso 1");

    // agregar arreglo
    TEST_CHECK_(addArray("arrayChar","char",2)==(0), "Caso 2");

    // estructura
    vector<string> subType = { "int", "arrayChar", "int" }; 
    TEST_CHECK_(addStruct("st",subType)==(0), "Caso 3");

    // Describir
    TEST_CHECK_(getDesperdicio("st",0)==(2), "Caso 4");
    TEST_CHECK_(getDesperdicio("st",1)==(1), "Caso 4");
    TEST_CHECK_(getDesperdicio("st",2)==(0), "Caso 4");
    TEST_CHECK_(getDesperdicio("st",3)==(1), "Caso 4");

    // No existe 
    int pos = 0;
    TEST_CHECK_((getEnd("ll", 2, pos))==(2), "Caso 5");

    // ya existe
    TEST_CHECK_((addAtomic("bool", 1, 2))==(1), "Caso 6");
    TEST_CHECK_((addArray("bool", "char", 2))==(1), "Caso 6");
}

TEST_LIST = {
	{"Test con todas las opciones", test_all},
	{0}
};
