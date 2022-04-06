#include "acutest.hpp"
#include "handler.hpp"

void test_all(void){
    // evaluacion
    pair<int,string> expected = { 0, "42" };
    TEST_CHECK_(mainHandler("EVAL","PRE","+ * + 3 4 5 7")==(expected), "Caso 1.1 evaluacion");
    expected = {0,"69"};
    TEST_CHECK_(mainHandler("EVAL","POST","8 3 - 8 4 4 + * +")==(expected), "Caso 1.2 evaluacion");

    // mostrar
    expected = {0,"(3+4)*5+7"};
    TEST_CHECK_(mainHandler("MOSTRAR","PRE","+ * + 3 4 5 7")==(expected), "Caso 2.1 mostrar");
    expected = {0,"8-3+8*(4+4)"};
    TEST_CHECK_(mainHandler("MOSTRAR","POST","8 3 - 8 4 4 + * +")==(expected), "Caso 2.2 mostrar");
    expected = {0,"2-(1+3)"};
    TEST_CHECK_(mainHandler("MOSTRAR", "PRE", "- 2 + 1 3")==(expected), "Caso 2.3 mostrar");
    expected = {0,"1-(2+3)"};
    TEST_CHECK_(mainHandler("MOSTRAR", "POST", "1 2 3 + -")==(expected), "Caso 2.4 mostrar");
    expected = {0,"2+3*4"};
    TEST_CHECK_(mainHandler("MOSTRAR", "POST", "2 3 4 * +")==(expected), "Caso 2.5 mostrar");
    expected = {0,"1/(2/3)"};
    TEST_CHECK_(mainHandler("MOSTRAR", "PRE", "/ 1 / 2 3")==(expected), "Caso 2.5 mostrar");
}

TEST_LIST = {
	{"Prueba completa de todas las funciones de handler.cpp", test_all},
	{0}
};
