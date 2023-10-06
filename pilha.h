// FILA DINAMICA
#ifndef PILHA_H
#define PILHA_H
//#include "No.h"

typedef struct no No;
typedef struct pilha Pilha;


void criaPilha(Pilha **pilha);
void empilhar(Pilha *pilha, char VERTICE[MAX_STRING]);
Pilha *desempilhar(Pilha **pilha);
void mostra(Pilha *pilha);
void limparPilha(Pilha **pilha);


#endif
