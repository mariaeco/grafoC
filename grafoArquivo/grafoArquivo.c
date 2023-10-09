#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "grafo.h"
#include "fila.h"
#include "pilha.h"
#include "no.h"



Grafo* criaGrafoArq(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(1);
    }
    char linha[MAX_STRING];
    int numvert = 0;

    // Ler o número de cidades do arquivo CSV
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numvert = atoi(linha);
    }
    printf("numCidades: %d\n",numvert);

    if (numvert == 0) {
        printf("Número de cidades nao encontrado no arquivo CSV.\n");
        fclose(arquivo);
        exit(1);
    }

    Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
    if (gr == NULL) {
        printf("Erro ao alocar memória para o grafo.\n");
        exit(1);
    }
    gr->maxVertices = numvert;
    gr->nVertices = numvert;

    gr->marcador = (bool*)malloc(numvert*sizeof(bool));// matriz para marcar os nos ja pesquisados

    gr->adjList = (No**)malloc(numvert * sizeof(No*));
    if (gr->adjList == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Ler e escreer nomes das cidades do arquivo CSV
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        int vertIndex = 0;

        while (token != NULL && vertIndex < numvert) {
            gr->adjList[vertIndex] = criarNo(token);
            token = strtok(NULL, ",");
            vertIndex++;
        }
    }

    // MINHA MATRIZ DE ADJACENCIAS
    int i, j;
    gr->adjmatrix = (int **)malloc(numvert * sizeof(int *));
    for (i = 0; i < numvert; i++) {
            gr->adjmatrix[i] = (int *)malloc(numvert * sizeof(int));
    }
    if (gr->adjmatrix == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    
   
    //PREENCHENDO A MATRIZ 
    for (int i = 0; i < numvert; i++) {
        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            char *token = strtok(linha, ",");
            int vertIndex = 0;

            while (token != NULL && vertIndex < numvert) {
                gr->adjmatrix[i][vertIndex] = atoi(token);
                token = strtok(NULL, ",");
                vertIndex++;
            }
        }
    }

    return gr;
}

