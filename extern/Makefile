all:
	gcc -Wall -fPIC -c -o csphi.o autogen-casadi-function.c
	gcc -Wall -fPIC -c -o icasadi.o icasadi.c
	gcc -Wall  -o icasadirunner main.c csphi.o icasadi.o -lm

run: all
	./icasadirunner

clean:
	rm -rf *.o
	rm -f ./icasadirunner

.PHONY: run, clean, all, icasadirunner
