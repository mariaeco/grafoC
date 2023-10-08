// FILA DINAMICA
#ifndef PILHA_H
#define PILHA_H
#include "no.h"


typedef struct pilha Pilha;


Pilha *criaPilha();
void empilhar(Pilha *pilha, char VERTICE[MAX_STRING]);
No *desempilhar(Pilha *pilha);
void mostraPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
void limparPilha(Pilha *pilha);
void mostraPilha(Pilha *pilha);

#endif
