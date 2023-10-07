// FILA DINAMICA
#ifndef PILHA_H
#define PILHA_H


typedef struct no No;
typedef struct pilha Pilha;


Pilha *criaPilha();
void empilhar(Pilha *pilha, char VERTICE[MAX_STRING]);
void desempilhar(Pilha *pilha);
void mostraPilha(Pilha *pilha);
void limparPilha(Pilha *pilha);


#endif
