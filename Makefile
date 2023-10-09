all: MeuGrafo

MeuGrafo: main.o grafo.o fila.o pilha.o menu.o grafoArquivo.o
	gcc main.o grafo.o fila.o pilha.o menu.o grafoArquivo.o -o MeuGrafo

main.o: main.c grafo.h fila.h pilha.h menu.o
	gcc -c main.c -o main.o

grafo.o: grafo.c grafo.h
	gcc -c grafo.c -o grafo.o

fila.o: fila.c fila.h
	gcc -c fila.c -o fila.o
	
pilha.o: pilha.c pilha.h
	gcc -c pilha.c -o pilha.o

menu.o: menu.c menu.h
	gcc -c menu.c -o menu.o

grafoArquivo.o: grafoArquivo/grafoArquivo.c
	gcc -I. -IgrafoArquivo -c grafoArquivo/grafoArquivo.c -o grafoArquivo.o

clean:
	rm -f *.o MeuGrafo