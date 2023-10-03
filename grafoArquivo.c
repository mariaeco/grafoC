//GRAFO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

#define MAX_STRING 30


struct no{ //nos da lista
    char cidade[MAX_STRING];
    struct no* prox;
};

struct grafo{
    int maxVertices;
    int nVertices;
    No** adjList;  //vetor de ponteiros para lista de adjancencias
    int **adjmatrix;
};

No* criarNo(char *CITY) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    strncpy(novo->cidade, CITY, sizeof(novo->cidade)); // Copie o nome para a estrutura
    novo->prox = NULL;
    return novo;
}


// Função para criar um grafo a partir de um arquivo CSV
Grafo* criaGrafoArquivo(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(1);
    }

    char linha[MAX_STRING];
    int numCidades = 0;

    // Ler o número de cidades do arquivo CSV
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numCidades = atoi(linha);
    }
    printf("numCidades: %d\n",numCidades);

    if (numCidades == 0) {
        printf("Número de cidades nao encontrado no arquivo CSV.\n");
        fclose(arquivo);
        exit(1);
    }

    Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
    if (gr == NULL) {
        printf("Erro ao alocar memória para o grafo.\n");
        exit(1);
    }
    gr->maxVertices = numCidades;
    gr->nVertices = numCidades;

    gr->adjList = (No**)malloc(numCidades * sizeof(No*));
    if (gr->adjList == NULL) {
        printf("Erro ao alocar memória para a lista de adjacências.\n");
        exit(1);
    }

    gr->adjmatrix = (int **)malloc(numCidades * sizeof(int *));
    for (int i = 0; i < numCidades; i++) {
        gr->adjmatrix[i] = (int *)malloc(numCidades * sizeof(int));
    }

    // Inicializar a lista de adjacências com NULL
    for (int i = 0; i < numCidades; i++) {
        gr->adjList[i] = NULL;
    }

    // Ler nomes das cidades do arquivo CSV
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        int cidadeIndex = 0;

        while (token != NULL && cidadeIndex < numCidades) {
            gr->adjList[cidadeIndex] = criarNo(token);
            token = strtok(NULL, ",");
            cidadeIndex++;
        }
    }

    // Ler a matriz de adjacências do arquivo CSV
    for (int i = 0; i < numCidades; i++) {
        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            char *token = strtok(linha, ",");
            int cidadeIndex = 0;

            while (token != NULL && cidadeIndex < numCidades) {
                gr->adjmatrix[i][cidadeIndex] = atoi(token);
                token = strtok(NULL, ",");
                cidadeIndex++;
            }
        }
    }

    fclose(arquivo);
    return gr;
}



void addVertice(Grafo *gr){
    char nome[MAX_STRING];
    int n=0;
    while(n < gr->maxVertices){
        printf("Digite  nome da cidade %d: ", n+1);
        scanf("%[^\n]%*c", &nome);
        gr->adjList[n] = criarNo(nome);
        n++;
    }
}

void addAresta(Grafo *gr, char *city1, char *city2, int dist){
    int i = findIndice(gr, city1);
    int j = findIndice(gr, city2);
    gr->adjmatrix[i][j] = dist;

    // Crie um novo nó para a cidade de destino (city2)
    No *novoNo = criarNo(gr->adjList[j]->cidade);

    // Obtenha o primeiro nó da lista de adjacência do vértice city1
    No *atual = gr->adjList[i];

    // Percorra a lista até encontrar o último nó
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Adicione o novo nó ao final da lista
    atual->prox = novoNo;
}

int findIndice(Grafo *gr, char *cidadeX) {
    for (int i = 0; i < gr->maxVertices; i++) {
        if (strcmp(gr->adjList[i]->cidade, cidadeX) == 0) {
            printf("%d", i);
            return i; // Retorna o índice da cidade X
        }
    }
    return -1, printf("\nCidade nao encontrada z \n"); // Retorna -1 se a cidade X não for encontrada
}

void printVertices(Grafo *gr){
    Grafo *aux = gr;
    printf(" ----------- LISTA DE ADJACENCIAS ---------------\n");
    for (int i = 0; i < gr->maxVertices; i++) {
        printf("%s: ",gr->adjList[i]->cidade);
        No *atual = gr->adjList[i]->prox; // Comece do primeiro nó após o vértice
        while (atual != NULL) {
            printf("%s ->", atual->cidade);
            atual = atual->prox;
        }
        printf("\n");
    }
}


void printadjMatrix(Grafo *gr) {
    int i, j;
    
    printf(" ----------- MATRIZ DE ADJACENCIAS ---------------\n");
    printf("            ");
    
    // Imprimir os nomes das cidades a partir da lista de adjacências
    for (i = 0; i < gr->maxVertices; i++) {
        printf("%-15s", gr->adjList[i]->cidade);
    }
    printf("\n");
    for (j = 0; j < gr->maxVertices; j++) {
        printf("%-15s", gr->adjList[j]->cidade);
        for (i = 0; i < gr->maxVertices; i++) {
            printf("%-15d", gr->adjmatrix[j][i]);
        }
        printf("\n");
    }
}




