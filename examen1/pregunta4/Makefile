CC = g++
CFLAGS = -g -w -Wall

# link de acutest.hpp
# https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h

main: main.o
	$(CC) $(CFLAGS) -o main main.o

test_unit_coverage:
	g++ --coverage test_unit.cpp -c
	g++ --coverage test_unit.o
	./a.out
	gcov test_unit.cpp -m
	# luego, geany manejador.cpp.gcov


test_unit: test_unit.o 
	$(CC) $(CFLAGS) -o test_unit test_unit.o

clean: 
	rm -f core *.o *.gcov *.gcno *.gcda main test_unit a.out
