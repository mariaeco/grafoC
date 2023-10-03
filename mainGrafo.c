#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main(){
    int nvert = 5;//numero de vertices
    int city1, city2, distancia;
    Grafo *gr = criaGrafo(nvert);

    system("cls");
    //ADICIONAR AS CIDADES JP, CG, Patos, Pilar, Itabaiana

    

    addAresta(gr, "JP", "CG", 30);
    addAresta(gr, "JP", "Patos", 20);
    addAresta(gr, "CG", "Patos", 50);
    addAresta(gr, "Patos", "Pilar", 10);
    addAresta(gr, "Pilar", "Itabaiana", 5);
    addAresta(gr, "Itabaiana", "Patos", 35);
    

   
    printf("\n\n");
    printVertices(gr);

    printf("\n\n");
    printadjMatrix(gr);

    system("pause");
    

    return 0;
}

