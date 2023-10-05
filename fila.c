
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "fila.h"

struct no{
    char vert[MAX_STRING];
    struct no *proximo;
};

struct fila{
    No *inicio;
    No *fim;
    int tam;
};

void criarFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
    printf("\nFila Criada com Sucesso!\n");
}

void inserir(Fila *fila, char VERTICE[MAX_STRING]){
    No *aux;
    No *novo = (No*)malloc(sizeof(No));

    if(novo != NULL){
        strncpy(novo->vert, VERTICE, sizeof(novo->vert)-1); // Copie o nome para a estrutura
        novo->vert[sizeof(novo->vert) - 1] = '\0'; // Garanta que o campo vertice seja nulo-terminado

        
        novo->proximo = NULL;
        if(fila->inicio == NULL){ //inserçao do meu primeiro no
            fila->inicio = novo;
            fila->fim = novo;
        }else{
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }else{
        printf("Memoria nao alocada\n\n");
    }
}

No* remover(Fila *fila){
    No *remover = NULL;

    if(fila->inicio){
        remover = fila->inicio;
        fila->inicio = remover->proximo;
        fila->tam--;
    }else{
        printf("\tFila vazia\n");
    }
    return remover;
}

void imprimirFila(Fila *fila){
    No *aux;

    aux = fila->inicio;
    printf("-------------- Fila ----------------\n");
    while(aux){
        printf("Vertice: %s ->",aux->vert);
        aux = aux->proximo;
    }
    printf("Fim da fila\n");
    printf("Tamanho da fila: %d\n\n", fila->tam);
}
