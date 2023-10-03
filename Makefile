all: MeuGrafo MeuGrafoArq

MeuGrafo: main.o grafo.o
	gcc main.o grafo.o -o MeuGrafo

MeuGrafoArq: mainGrafoArq.o grafoArquivo.o
	gcc mainGrafoArq.o grafoArquivo.o -o MeuGrafoArq

main.o: mainGrafo.c grafo.h
	gcc -c mainGrafo.c -o main.o

mainGrafoArq.o: mainGrafoArq.c grafo.h
	gcc -c mainGrafoArq.c -o mainGrafoArq.o

grafo.o: grafo.c grafo.h
	gcc -c grafo.c -o grafo.o

grafoArquivo.o: grafoArquivo.c grafo.h
	gcc -c grafoArquivo.c -o grafoArquivo.o

clean:
	rm -f *.o MeuGrafo MeuGrafoArq