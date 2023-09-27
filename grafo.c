#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct no{ //nos da lista
    int vertice;
    struct no* prox;
};

struct grafo{
    int nVertices;
    No** adjList;  //vetor de ponteiros para lista de adjancencias
};


No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->vertice = valor;
    novo->prox = NULL;
    return novo;
};

Grafo* criaGrafo(int vertices){
    Grafo* gr = malloc(sizeof(Grafo));
    gr->nVertices = vertices;

    gr->adjList = malloc(vertices*sizeof(No*));

    int i;
    for (i=0; i<vertices; i++){
        gr->adjList[i] = NULL;
    }
    return gr;
};


void adicionarAresta(Grafo* gr, int s, int t){
    // s para t
    No* novo = criarNo(t);
    novo->prox = gr->adjList[s];
    gr->adjList[s] = novo;

    // t para s
    novo = criarNo(s);
    novo->prox = gr->adjList[t];
    gr->adjList[t] = novo;

};

void printGrafo(Grafo *gr){
    int v;
    for(v=0; v< gr->nVertices; v++){
        No* temp = gr->adjList[v];
        printf("\n%d: ", v);
        while(temp){
            printf("%d -> ", temp->vertice);
            temp = temp->prox;
        }
    }
};
    
