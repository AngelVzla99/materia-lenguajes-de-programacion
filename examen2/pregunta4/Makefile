CC = g++
CFLAGS = -I -g -w -Wall
IP = python3

# link de acutest.hpp
# https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h

main: main.cpp funcs.cpp
	$(CC) $(CFLAGS) -o main main.cpp funcs.cpp

generateData: main.cpp funcs.cpp
	$(CC) $(CFLAGS) -o main main.cpp funcs.cpp
	$ ./main -d < testCases > tiempoDirecto
	$ ./main -c < testCases > tiempoCola
	$ ./main -i < testCases > tiempoIterativo

makePlots:
	$ python3 plotFiles.py plotAll tiempoDirecto tiempoCola tiempoIterativo
	$ python3 plotFiles.py plotColaIterativo tiempoCola tiempoIterativo

clean: 
	rm -f core *.o *.gcov *.gcno *.gcda main test_unit a.out tiempo*
