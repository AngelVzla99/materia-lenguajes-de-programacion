#include "acutest.hpp"
#include "util.hpp"

void test_add(void){
	int v1 = 2, v2 = 2;
	TEST_CHECK_(add(v1,v2)==(v1+v2), "add(%d,%d)==%d", v1, v2, (v1+v2));
	for(int v1=0; v1<4; v1++){
		for(int v2=0; v2<3; v2++){
			TEST_CHECK_(add(v1,v2)==(v1+v2), "add(%d,%d)==%d", v1, v2, (v1+v2));
		}
	}
	v1 = 2; v2 = 2;
	TEST_CHECK_(add(v1,v2)==(7), "mensaje ? add(%d,%d)==%d", v1, v2, (7));
	TEST_CHECK_(add(v1,v2)==(7), "epa add(%d,%d)==%d", v1, v2, (7));
}

TEST_LIST = {
	{"int add(int,int);", test_add},
	{0}
};
