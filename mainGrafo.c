#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main(){
    int nvert = 5;//numero de vertices
    Grafo *gr = criaGrafo(nvert);

    adicionarAresta(gr, 0, 1);
    adicionarAresta(gr, 0, 2);
    adicionarAresta(gr, 0, 3);
    adicionarAresta(gr, 1, 2);
    adicionarAresta(gr, 2, 3);
    adicionarAresta(gr, 4, 2);

    printGrafo(gr);

    return 0;
}