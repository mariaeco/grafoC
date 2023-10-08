#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "pilha.h"
#include "no.h"



struct pilha{
    No *topo;
    int tam;
};


//Funcao de criacao de Pilha
Pilha *criaPilha(){ //
    Pilha *pilha = (Pilha *)malloc(sizeof(pilha));
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
  
    pilha->topo = NULL; // ou 0
    pilha->tam = 0;
    //printf("Pilha criada!\n");

    return pilha;
}

int pilhaVazia(Pilha *pilha){
    return (pilha->topo==NULL);
}

//FUNCAO PARA EMPILHAR (push)
void empilhar(Pilha *pilha, char VERTICE[MAX_STRING]){ // quase igual cria nó da Pilha dupla

    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }else{
        strncpy(novo->vertice, VERTICE, sizeof(novo->vertice)-1); // Copie o nome para a estrutura
        novo->vertice[sizeof(novo->vertice) - 1] = '\0'; // Garanta que o campo vertice seja nulo-terminado
        novo->prox = pilha->topo;
        pilha->topo = novo;
        pilha->tam++;
    }
}


No *desempilhar(Pilha *pilha){
    if(pilha->topo != NULL){
        No *remover = pilha->topo;
        pilha->topo = pilha->topo->prox;    
       // printf("\nElemento removido com sucesso\n");
        pilha->tam--;
        return remover;
    }else{
        printf("Pilha Vazia!\n");
        return 0;
    }
}

void limparPilha(Pilha *pilha){
    No *remover; // cria uma copia para nao perder o endereço
    while(pilha->topo){
        remover = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(remover);
    }
    if(pilha->topo== NULL){
        printf("\nPilha deletada com sucesso\n");
    }
    
}


void mostraPilha(Pilha *pilha){
    No *aux = pilha->topo;
    printf("\n------------- PILHA ------------------\n");
    while(aux){
        printf("%s\n",aux->vertice);
        aux = aux->prox;
    }
    if(pilha->topo == NULL){
        printf("\nPILHA VAZIA\n");
    }
    printf("\n---------- FIM DA PILHA -------------\n");
    
}

