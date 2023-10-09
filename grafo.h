#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>
#include "no.h"
#define ARESTANULA 0


typedef struct no No; //lista de adjacencias
typedef struct grafo Grafo;

struct grafo{
    int maxVertices;
    int nVertices;
    No** adjList;  //vetor de ponteiros para lista de adjancencias
    int **adjmatrix;
    bool* marcador; // marcador para indicar se ja vou visitado ou nao
};

No* criarNo(char VERTICE[MAX_STRING]);
Grafo* criaGrafo(int nvertices, char *vertices[MAX_STRING]);
void addVertice(Grafo *gr, char *nome[MAX_STRING]);
void addAresta(Grafo *gr, char origem[MAX_STRING], char destino[MAX_STRING], int dist);
void printadjMatrix(Grafo *gr);
void printVertices(Grafo *gr);
int findIndice(Grafo *gr, char nomevertice[MAX_STRING]);
void destroiGrafo(Grafo *gr);
void buscaLargura(Grafo* gr, char origem[MAX_STRING], char destino[MAX_STRING]);
void buscaProfundidade(Grafo* gr, char origem[MAX_STRING], char destino[MAX_STRING]);
void limpamarcador(Grafo *gr);
Grafo* criaGrafoArq(char* nomeArquivo);


#endif