
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "fila.h"
#include "no.h"

struct fila{
    No *inicio;
    No *fim;
    int tam;
};

void criarFila(Fila **fila){
    *fila = (Fila *)malloc(sizeof(Fila));
    if (*fila == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
    (*fila)->tam = 0;
    //printf("\nFila Criada com Sucesso!\n");
}

void inserir(Fila *fila, char VERTICE[MAX_STRING]){
    No *novo = (No*)malloc(sizeof(No));

    if(novo != NULL){
        strncpy(novo->vertice, VERTICE, sizeof(novo->vertice)-1); // Copie o nome para a estrutura
        novo->vertice[sizeof(novo->vertice) - 1] = '\0'; // Garanta que o campo vertice seja nulo-terminado
        novo->prox = NULL;
        if(fila->inicio == NULL){ //inserçao do meu primeiro no
            fila->inicio = novo;
            fila->fim = novo;
        }else{
            fila->fim->prox = novo;
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
        fila->inicio = remover->prox;
        fila->tam--;
    }else{
        printf("\tFila vazia\n");
    }
    return remover;
}

int filavazia(Fila *fila){
    return (fila->inicio == NULL);
}

void imprimirFila(Fila *fila){
    No *aux;

    aux = fila->inicio;
    //printf("-------------- Fila ----------------\n");
    while(aux){
        printf("%s -> ",aux->vertice);
        aux = aux->prox;
    }
    printf("Tamanho da fila: %d\n", fila->tam);
}
