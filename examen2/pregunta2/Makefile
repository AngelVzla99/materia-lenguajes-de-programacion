CC = g++
CFLAGS = -g -w -Wall

# link de acutest.hpp
# https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h

main: main.o handler.o
	$(CC) $(CFLAGS) -o main main.o handler.o

test_unit_coverage:test_unit.o
	g++ --coverage handler.cpp test_unit.cpp -c
	g++ --coverage handler.o test_unit.o
	./a.out
	gcov handler.cpp -m
	# luego, geany manejador.cpp.gcov

test_unit: test_unit.o handler.o
	$(CC) $(CFLAGS) -o test_unit test_unit.o handler.o

handler.o: handler.hpp handler.cpp 
	$(CC) $(CFLAGS) -c handler.cpp

clean: 
	rm -f core *.o *.gcov *.gcno *.gcda main test_unit a.out
