#ifndef GRAFO_H
#define GRAFO_H


typedef struct no No; //lista de adjacencias
typedef struct grafo Grafo;

No* criarNo(char *cidade);
Grafo* criaGrafo(int cidade);
void addVertice(Grafo *gr);
void addAresta(Grafo *gr, char *city1, char *city2, int dist);
void printadjMatrix(Grafo *gr);
void printVertices(Grafo *gr);
int findIndice(Grafo *gr, char *cidadeX);
#endif