#ifndef GRAFO_H
#define GRAFO_H


typedef struct no No; //lista de adjacencias
typedef struct grafo Grafo;

No* criarNo(int valor);
Grafo* criaGrafo(int vertices);
void adicionarAresta(Grafo* gr, int s, int t);
void printGrafo(Grafo *gr);

#endif