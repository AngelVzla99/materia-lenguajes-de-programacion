CC = g++
CFLAGS = -I -g -w -Wall -std=c++17

# link de acutest.hpp
# https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h

main: main.cpp handler.cpp
	$(CC) $(CFLAGS) -o main main.cpp handler.cpp

unit_test: unit_test.cpp handler.cpp 
	$(CC) $(CFLAGS) -o unit_test unit_test.cpp handler.cpp 

unit_test_coverage: unit_test.cpp 
	g++ --coverage handler.cpp unit_test.cpp -c
	g++ --coverage handler.o unit_test.o
	./a.out 
	gcov handler.cpp -m
	# luego, geany handler.cpp.gcov

clean: 
	rm -f core *.o *.gcov *.gcno *.gcda main unit_test a.out tiempo*
