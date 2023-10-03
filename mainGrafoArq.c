#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main(){
    int nvert = 5;//numero de vertices
    int city1, city2, distancia;
    Grafo *gr = criaGrafoArquivo("matrizdedistancias.csv");

   
    printf("\n\n");
    printVertices(gr);

    printf("\n\n");
    printadjMatrix(gr);

    system("pause");
    

    return 0;
}

