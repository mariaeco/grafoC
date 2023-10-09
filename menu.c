#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "menu.h"


Grafo*  menu_02 (Grafo *gr){
    int nvertices;//numero de vertices
    char origem[MAX_STRING];
    char destino[MAX_STRING];
    int dist;
    int opcao;
    char **vertices;
    int continuar = 1; // Variável de controle

    do{
            
        printf("\nMenu:\n");
        printf("1. Digite o numero de vertices\n");
        printf("2. Digite os nomes dos vertices\n");
        printf("3. Inclua as arestas\n");
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
                                //printf("i: %d, j: %d",i, j);
                            }
                        contador ++;    
                        }
                    }
                }
                system("pause");
                system("cls");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
            
        }
    }while(opcao != 0);

    return gr;
}
