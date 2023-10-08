all: MeuGrafo MeuGrafoArq

MeuGrafo: main.o grafo.o fila.o pilha.o
	gcc main.o grafo.o fila.o pilha.o -o MeuGrafo

MeuGrafoArq: mainGrafoArquivo.o grafoArquivo.o
	gcc mainGrafoArquivo.o grafoArquivo.o -o MeuGrafoArq

main.o: main.c grafo.h fila.h pilha.h
	gcc -c main.c -o main.o

mainGrafoArquivo.o: grafoArquivo/mainGrafoArquivo.c
	gcc -I. -IgrafoArquivo -c grafoArquivo/mainGrafoArquivo.c -o mainGrafoArquivo.o

grafo.o: grafo.c grafo.h
	gcc -c grafo.c -o grafo.o

fila.o: fila.c fila.h
	gcc -c fila.c -o fila.o
	
pilha.o: pilha.c pilha.h
	gcc -c pilha.c -o pilha.o

grafoArquivo.o: grafoArquivo/grafoArquivo.c
	gcc -I. -IgrafoArquivo -c grafoArquivo/grafoArquivo.c -o grafoArquivo.o

clean:
	rm -f *.o MeuGrafo MeuGrafoArq