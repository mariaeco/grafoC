#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "no.h"




int main(){
    int nvertices;//numero de vertices
    char origem[MAX_STRING];
    char destino[MAX_STRING];
    int dist;
    int opcao;
    char **vertices;
    Grafo *gr;

    
    system("cls");

    do {
        printf("\nMenu:\n");
        printf("1. Digite o numero de vertices\n");
        printf("2. Digite os nomes dos vertices\n");
        printf("3. Inclua as arestas\n");
        printf("4. Imprima a lista de adjacencias\n");
        printf("5. Imprima a matriz de adjacencias\n");
        printf("6. Realize a busca em largura\n");
        printf("7. Realize a busca em profundidade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero de vertices: ");
                scanf("%d", &nvertices);
                vertices = (char **)malloc(nvertices * sizeof(char *));
                if (vertices == NULL) {
                    printf("Erro ao alocar memoria para os vertices.\n");
                    exit(1);
                }
                system("cls");
                break;
            case 2:
                if (vertices == NULL) {
                    printf("Primeiro, digite o numero de vertices (opção 1).\n");
                } else {
                    char nome[MAX_STRING];
                    for (int i = 0; i < nvertices; i++) {
                        printf("Digite o nome do vertice %d: ", i + 1);
                        vertices[i] = (char *)malloc(MAX_STRING * sizeof(char));
                        if (vertices[i] == NULL) {
                            printf("Erro ao alocar memoria para o vertice.\n");
                            exit(1);
                        }
                        scanf(" %[^\n]%*c", vertices[i]);// %[^\n]%*c
                    }
                    gr = criaGrafo(nvertices, vertices);
                }
                system("pause");
                system("cls");
                break;
            case 3:
                if (gr == NULL) {
                    printf("Primeiro, crie o grafo (opcao 2).\n");
                } else {
                    printf("Se existir caminho, digite a origem, o destino, e valor da aresta.\n");
                    printf("Vertices ");
                    for(int i = 0; i < nvertices; i++){
                        printf(" -> %s ", vertices[i]);
                    }
                    for(int j = 0; j < nvertices; j++){
                        int contador = 1+j;
                        for(int i = contador; i < nvertices; i++){
                            if(strcmp(vertices[j], vertices[i])==0){
                                addAresta(gr, vertices[j], vertices[i], 0);
                                addAresta(gr, vertices[i], vertices[j], 0);
                            }else{
                                printf("\n Digite a distancia entre %s e %s: ", vertices[j], vertices[i]);
                                scanf("\n %d", &dist);
                                addAresta(gr, vertices[j], vertices[i], dist);
                                printf("Digite a distancia entre %s e %s: ", vertices[i], vertices[j]);
                                scanf("\n %d", &dist);
                                addAresta(gr, vertices[i], vertices[j], dist);
                                printf("i: %d, j: %d",i, j);
                            }
                            contador ++;    
                        }
                    }
                }
                system("pause");
                system("cls");
                break;
            case 4:
                if (gr == NULL) {
                    printf("Primeiro, crie o grafo (opcao 2).\n");
                } else {
                    printVertices(gr);
                }
                system("pause");
                system("cls");
                break;
            case 5:
                if (gr == NULL) {
                    printf("Primeiro, crie o grafo (opcao 2).\n");
                } else {
                    printf("Matriz de Adjacencias:\n");
                    printadjMatrix(gr);
                }
                system("pause");
                system("cls");
                break;
            case 6:
                if (gr == NULL) {
                    printf("Primeiro, crie o grafo (opcao 2).\n");
                } else {
                    printf("Digite o vertice de origem: ");
                    scanf("%s", origem);
                    printf("Digite o vertice de destino: ");
                    scanf("%s", destino);
                    buscaLargura(gr, origem, destino);
                }
                system("pause");
                system("cls");
                break;
            case 7:
                if (gr == NULL) {
                    printf("Primeiro, crie o grafo (opcao 2).\n");
                } else {
                    printf("Digite o vertice de origem: ");
                    scanf("%s", origem);
                    printf("Digite o vertice de destino: ");
                    scanf("%s", destino);
                    buscaProfundidade(gr, origem, destino);
                }
                system("pause");
                system("cls");
                break;
            case 0:
                // Libere a memória alocada para os vértices
                if (vertices != NULL) {
                    for (int i = 0; i < nvertices; i++) {
                        free(vertices[i]);
                    }
                    free(vertices);
                }
                // Libere a memória alocada para o grafo
                if (gr != NULL) {
                    destroiGrafo(gr);
                }
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

