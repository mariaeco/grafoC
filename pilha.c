#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "pilha.h"

struct no{
    char vert[MAX_STRING];
    struct no *proximo;
};

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
    printf("Pilha criada!\n");

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
        strncpy(novo->vert, VERTICE, sizeof(novo->vert)-1); // Copie o nome para a estrutura
        novo->vert[sizeof(novo->vert) - 1] = '\0'; // Garanta que o campo vertice seja nulo-terminado
        novo->proximo = pilha->topo;
        pilha->topo = novo;
        pilha->tam++;
    }
}


void desempilhar(Pilha *pilha){
    if(pilha->topo != NULL){
        No *remover = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(remover);
        printf("\nElemento removido com sucesso\n");
        pilha->tam--;
    }else{
        printf("Pilha Vazia!\n");
    }
}

void limparPilha(Pilha *pilha){
    No *remover; // cria uma copia para nao perder o endereço
    while(pilha->topo){
        remover = pilha->topo;
        pilha->topo = pilha->topo->proximo;
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
        printf("%s\n",aux->vert);
        aux = aux->proximo;
    }
    if(pilha->topo == NULL){
        printf("\nPILHA VAZIA\n");
    }
    printf("\n---------- FIM DA PILHA -------------\n");
    
}

