// FILA DINAMICA
#ifndef FILA_H
#define FILA_H
//#include "No.h"

typedef struct no No;
typedef struct fila Fila;

void criarFila(Fila *fila);
void inserir(Fila *fila, char vert[MAX_STRING]);
No* remover(Fila *fila);
void imprimirFila(Fila *fila);


#endif

