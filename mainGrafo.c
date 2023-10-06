#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

int main(){
    int nvert = 5;//numero de vertices
    int city1, city2, distancia;
    char *vertices[MAX_STRING] = {"JP", "CG", "Patos", "Pilar", "Itabaiana"};
    Grafo *gr;
    Fila *fila;


    system("cls");

    gr = criaGrafo(nvert, vertices);
    criarFila(&fila);

    
    addAresta(gr, "JP", "CG", 30);
    addAresta(gr, "JP", "Patos", 20);
    addAresta(gr, "CG", "Patos", 50);
    addAresta(gr, "Patos", "Pilar", 10);
    addAresta(gr, "Pilar", "Itabaiana", 5);
    addAresta(gr, "Itabaiana", "Patos", 35);
    
    printf("\n");
    printVertices(gr);
 
    printf("\n");
    printadjMatrix(gr);
 
    
    
    system("pause");


    return 0;
}

