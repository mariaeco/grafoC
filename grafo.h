#ifndef GRAFO_H
#define GRAFO_H

#define MAX_STRING 15


typedef struct no No; //lista de adjacencias
typedef struct grafo Grafo;

No* criarNo(char VERTICE[MAX_STRING]);
Grafo* criaGrafo(int nvertices, char *vertices[MAX_STRING]);
void addVertice(Grafo *gr, char *nome[MAX_STRING]);
void addAresta(Grafo *gr, char origem[MAX_STRING], char destino[MAX_STRING], int dist);
void printadjMatrix(Grafo *gr);
void printVertices(Grafo *gr);
int findIndice(Grafo *gr, char nomevertice[MAX_STRING]);
void buscaLargura(Grafo* gr, char origem[MAX_STRING], char destino[MAX_STRING]);
void buscaProfundidade(Grafo* gr, char origem[MAX_STRING], char destino[MAX_STRING]);
void limparmarcador();


#endif