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
void criaPilha(Pilha **pilha){ //
    *pilha = (Pilha *)malloc(sizeof(pilha));
    if (*pilha == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
  
    (*pilha)->topo = NULL; // ou 0
    printf("Pilha criada!\n");

    system("pause");
    return ;

}

int pilhaVazia(Pilha *pilha){
    return (pilha->topo==NULL);


//FUNCAO PARA EMPILHAR (push)
void empilhar(Pilha *pilha, char VERTICE[MAX_STRING]){ // quase igual cria nó da Pilha dupla
   // Pilha* aux;
   // aux = pilha->topo;
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }else{
        strncpy(novo->vert, VERTICE, sizeof(novo->vert)-1); // Copie o nome para a estrutura
        novo->vert[sizeof(novo->vert) - 1] = '\0'; // Garanta que o campo vertice seja nulo-terminado
        novo->proximo = pilha->topo;
        pilha->topo = novo;
    }
}

/*
//FUNCAO PARA DESEMPILHAR (pop)
Pilha* desempilhar(Pilha **topo){
    if(*topo != NULL){
        Pilha *remover = *topo;
        *topo = remover->proximo;
        free(remover);
        printf("\nElemento removido com sucesso\n");
        return remover;
    }else{
        printf("Pilha Vazia!\n");
        return NULL;
    }
    system("pause");
}

void limparPilha(Pilha **topo){
    Pilha *remover; // cria uma copia para nao perder o endereço
    while(*topo){
        remover = *topo;
        *topo = remover->proximo;
        free(remover);
    }
    if(*topo == NULL){
        printf("\nPilha deletada com sucesso\n");
    }
    system("pause");
}

void mostra(Pilha *topo){
    printf("\n------------- PILHA ------------------");
    while(topo){
        imprimirDado(topo->info);
        topo = topo->proximo;
    }
    printf("\n---------- FIM DA PILHA -------------\n");
    system("pause");
}

*/