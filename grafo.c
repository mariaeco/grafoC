//GRAFO
//GRAFO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "grafo.h"
#include "fila.h"
#include "pilha.h"
#include "no.h"



No* criarNo(char VERTICE[MAX_STRING]) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strncpy(novo->vertice, VERTICE, sizeof(novo->vertice)-1); // Copie o nome para a estrutura
    novo->vertice[sizeof(novo->vertice) - 1] = '\0'; // Garanta que o campo vertice seja nulo-terminado
    novo->prox = NULL;
    return novo;
};

Grafo* criaGrafo(int nvertices, char *vertices[MAX_STRING]) {
    Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
    
    if (gr == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    gr->maxVertices = nvertices;

    gr->marcador = (bool*)malloc(nvertices*sizeof(bool));// matriz para marcar os nos ja pesquisados

    gr->adjList = (No**)malloc(nvertices * sizeof(No*));
    if (gr->adjList == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    addVertice(gr, vertices);
    // MINHA MATRIZ DE ADJACENCIAS
    int i, j;
    gr->adjmatrix = (int **)malloc(nvertices * sizeof(int *));
    for (i = 0; i < nvertices; i++) {
            gr->adjmatrix[i] = (int *)malloc(nvertices * sizeof(int));
    }
    if (gr->adjmatrix == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    
    //PREENCHENDO A MATRIZ COM ZEROS
    for(j=0; j < gr->maxVertices; j++){
        for(i=0; i < gr->maxVertices; i++){
            gr->adjmatrix[i][j] = ARESTANULA;
        }
    }

    return gr;
}

void addVertice(Grafo *gr, char* nome[MAX_STRING]){
    int n;
    printf(" ----------- VERTICES  ---------------\n");
    for (n=0; n < gr->maxVertices; n++){
        printf("Vertice: %s\n",nome[n]);
        gr->adjList[n] = criarNo(nome[n]);
    }
}

void addAresta(Grafo *gr, char vert1[MAX_STRING], 
                char vert2[MAX_STRING], int dist){
    int i = findIndice(gr, vert1);
    int j = findIndice(gr, vert2);

    gr->adjmatrix[i][j] = dist;//direcionado
    //gr->adjmatrix[j][i] = dist;//caso nao seja direcionado

    // Crie um novo nó para a vertice de destino (city2)
    No *novoNo = criarNo(gr->adjList[j]->vertice);

    // Obtenha o primeiro nó da lista de adjacência do vértice city1
    No *atual = gr->adjList[i];

    // Percorra a lista até encontrar o último nó
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Adicione o novo nó ao final da lista
    atual->prox = novoNo;
}

int findIndice(Grafo *gr, char nomevertice[MAX_STRING]) {
    for (int i = 0; i < gr->maxVertices; i++) {
        if (strcmp(gr->adjList[i]->vertice, nomevertice) == 0) {
            //printf("%d", i);
            return i; // Retorna o índice da vertice X
        }
    }
    return printf("\nVertice %s Nao Encontrado\n", nomevertice); // Retorna -1 se a vertice X não for encontrada
}

void printVertices(Grafo *gr){
    Grafo *aux = gr;
    printf(" ----------- LISTA DE ADJACENCIAS ---------------\n");
    for (int i = 0; i < gr->maxVertices; i++) {
        printf("%s ",gr->adjList[i]->vertice);

        No *atual = gr->adjList[i]->prox; // Comece do primeiro nó após o vértice
        while (atual != NULL) {
            printf("%s ->", atual->vertice);
            atual = atual->prox;
        }
    printf("\n");
    }
}


void printadjMatrix(Grafo *gr){
    int i, j;
    
    printf(" ----------- MATRIZ DE ADJACENCIAS ---------------\n");
    printf("            ");
    for (i = 0; i < gr->maxVertices; i++) {
        printf("%-15s", gr->adjList[i]);
    }
    printf("\n");
    
    for(j=0; j < gr->maxVertices; j++){
        printf("%-15s", gr->adjList[j]);
        for(i=0; i < gr->maxVertices; i++){
            printf("%-15d", gr->adjmatrix[i][j]);
        }
        printf("\n");
    }
}

void limpamarcador(Grafo *gr){
    for (int i = 0; i < gr->maxVertices; i++) {
        gr->marcador[i] =  false;
    }
}


void buscaLargura(Grafo* gr, char origem[MAX_STRING], char destino[MAX_STRING]){
    Fila *fila;
    criarFila(&fila);
    bool encontrado = false;
    
    limpamarcador(gr);
    
    inserir(fila, origem);
    int i = findIndice(gr, origem);
    gr->marcador[i] = true;
    
    printf("--------------Caminho de %s para %s--------------", origem, destino);

    do{
        No *atual = remover(fila);

           
        int indice = findIndice(gr, atual->vertice);
        int indicej = findIndice(gr, destino);
        //printf("Visitando: %s", atual->vertice);
            
        for(int j = 0; j <= indicej; j++){
            if(gr->adjmatrix[j][indice] != ARESTANULA){
                if(gr->marcador[j] == false){
                    atual = gr->adjList[j];
                    //printf("\nEnfileirando %s\n", atual->vertice);
                    inserir(fila, atual->vertice);
                    imprimirFila(fila);
                    gr->marcador[j] = true;
                    if(strcmp(atual->vertice, destino)==0){
                        printf("\nCaminho para %s Encontrado \n", destino);
                        encontrado = true;
                    }
                }
            }            
        }
    }while(filavazia(fila) && !encontrado);
    if(!encontrado){
        printf("\nCaminho para %s NAO Encontrado! \n", destino);
    }
}


void buscaProfundidade(Grafo* gr, char origem[MAX_STRING], char destino[MAX_STRING]){
    Pilha *pilha = criaPilha();
    bool encontrado = false;
    
    limpamarcador(gr);
    
    empilhar(pilha, origem);
    int i = findIndice(gr, origem);
    //printf("origem: %s \n", origem);
    //printf("indice: %i\n", i);
    gr->marcador[i] = true;
    
    printf("--------------Caminho de %s para %s --------------", origem, destino);

    do{
        No *atual = desempilhar(pilha);
        int indice = findIndice(gr, atual->vertice);
        int indicej = findIndice(gr, destino);
        gr->marcador[indice] = true;

        for(int j = 0; j <= indicej; j++){
            if(gr->adjmatrix[j][indice] != ARESTANULA){
                if(gr->marcador[j] == false){
                    atual = gr->adjList[j];
                    empilhar(pilha, atual->vertice);
                    mostraPilha(pilha);
                    if(strcmp(atual->vertice, destino)==0){
                        printf("\nCaminho para %s Encontrado \n\n", destino);
                        encontrado = true;
                    }
                }
            }            
        }
    }while(pilhaVazia(pilha) && !encontrado);
    if(!encontrado){
        printf("\nCaminho para %s NAO Encontrado! \n", destino);
    }
}


void destroiGrafo(Grafo* gr) {
    if (gr == NULL) {
        return; // Verifica se o grafo já foi destruído ou não foi criado
    }

    // Libera a memória alocada para a matriz de adjacências
    if (gr->adjmatrix != NULL) {
        for (int i = 0; i < gr->maxVertices; i++) {
            free(gr->adjmatrix[i]);
        }
        free(gr->adjmatrix);
    }

    // Libera a memória alocada para as listas de adjacência
    if (gr->adjList != NULL) {
        for (int i = 0; i < gr->maxVertices; i++) {
            No* atual = gr->adjList[i];
            while (atual != NULL) {
                No* temp = atual;
                atual = atual->prox;
                free(temp);
            }
        }
        free(gr->adjList);
    }

    // Libera a memória alocada para o vetor de marcadores
    if (gr->marcador != NULL) {
        free(gr->marcador);
    }

    // Finalmente, libera a estrutura de grafo
    free(gr);
}

