all: MeuGrafo MeuGrafoArq

MeuGrafo: main.o grafo.o
	gcc main.o grafo.o -o MeuGrafo

MeuGrafoArq: mainGrafoArquivo.o grafoArquivo.o
	gcc mainGrafoArquivo.o grafoArquivo.o -o MeuGrafoArq

main.o: mainGrafo.c grafo.h
	gcc -c mainGrafo.c -o main.o

mainGrafoArquivo.o: mainGrafoArquivo.c grafo.h
	gcc -c mainGrafoArquivo.c -o mainGrafoArquivo.o

grafo.o: grafo.c grafo.h
	gcc -c grafo.c -o grafo.o

grafoArquivo.o: grafoArquivo.c grafo.h
	gcc -c grafoArquivo.c -o grafoArquivo.o

clean:
	rm -f *.o MeuGrafo MeuGrafoArq