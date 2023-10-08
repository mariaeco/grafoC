#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main(){
    int nvert = 5;//numero de vertices
    int city1, city2, distancia;
    char *vertices[MAX_STRING] = {"JP", "CG", "Patos", "Pilar", "Itabaiana"};
    Grafo *gr;

    system("cls");

    gr = criaGrafo(nvert, vertices);

    
    addAresta(gr, "JP", "CG", 30);
    addAresta(gr, "JP", "Patos", 20);
    addAresta(gr, "CG", "JP", 32);
    addAresta(gr, "CG", "Patos", 50);
    addAresta(gr, "Patos", "Pilar", 10);
    addAresta(gr, "Patos", "CG", 52);
    addAresta(gr, "Pilar", "Itabaiana", 5);
    addAresta(gr, "Itabaiana", "Patos", 35);
    addAresta(gr, "JP", "Itabaiana", 10);
    addAresta(gr, "Itabaiana", "JP", 12);

    printf("\n");
    printVertices(gr);

    printf("\n");
    printadjMatrix(gr);

    printf("\n\n\n");
    buscaLargura(gr, "Patos", "Itabaiana");
    
    printf("\n\n\n");
    buscaLargura(gr, "Patos", "Patos");

    printf("\n\n");

    buscaProfundidade(gr, "JP", "Itabaiana");

    system("pause");


    return 0;
}

