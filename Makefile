all: MeuGrafo

MeuGrafo: main.o grafo.o 
	gcc main.o grafo.o -o MeuGrafo

main.o: mainGrafo.c grafo.h
	gcc -c mainGrafo.c -o main.o

grafo.o: grafo.c grafo.h
	gcc -c grafo.c -o grafo.o

clean:
	rm -f *.o
