#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "menu.h"



int main(){
    char origem[MAX_STRING];
    char destino[MAX_STRING];
    int nvertices;//numero de vertices
    int opcao;
    char **vertices;
    Grafo *gr;
    
    system("cls");

    do {
        printf("\nMenu:\n");
        printf("1. Entrar com arquivo\n");
        printf("2. Nao tenho arquivo, irei digitar os valores do grafo\n");
        printf("4. Imprima a lista de adjacencias\n");
        printf("5. Imprima a matriz de adjacencias\n");
        printf("6. Realize a busca em largura\n");
        printf("7. Realize a busca em profundidade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                gr = criaGrafoArq("matrizdedistancias.csv");
                break;
            case 2:
                gr = menu_02(gr);
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

