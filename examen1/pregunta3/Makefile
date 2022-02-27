CC = g++
CFLAGS = -g -w -Wall

# link de acutest.hpp
# https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h

main: main.o manejador.o
	$(CC) $(CFLAGS) -o main main.o manejador.o

test_unit_coverage:test_unit.o
	g++ --coverage manejador.cpp test_unit.cpp -c
	g++ --coverage manejador.o test_unit.o
	./a.out
	gcov manejador.cpp -m
	# luego, geany manejador.cpp.gcov

test_unit: test_unit.o manejador.o
	$(CC) $(CFLAGS) -o test_unit test_unit.o manejador.o

manejador.o: manejador.hpp manejador.cpp 
	$(CC) $(CFLAGS) -c manejador.cpp

clean: 
	rm -f core *.o *.gcov *.gcno *.gcda main test_unit a.out
