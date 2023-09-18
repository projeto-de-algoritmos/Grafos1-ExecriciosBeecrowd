#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Nome: Gabriel Marcolino Rodrigues
 * Matrícula: 190087501
*/

#define TAM 30

bool flag;
bool visitado[TAM];
char espaco[TAM];
int v, e;
int matrizAdjacencia[TAM][TAM];

void buscaProfundidade(int vertice) { 
    int i;
    visitado[vertice] = true;
    strcat(espaco, "  ");

    for (i = 0; i < v; ++i) {
        if (matrizAdjacencia[vertice][i]) {
            flag = true;

            if (!visitado[i]) {
                printf("%s%d-%d pathR(G,%d)\n", espaco, vertice, i, i);
                buscaProfundidade(i);
                espaco[strlen(espaco) - 2] = 0;
            } else {
                printf("%s%d-%d\n", espaco, vertice, i);
            }
        }
    }
}

int main() {
    int verticeOrigem, verticeDestino;
    int n, i, caso = 0;

    scanf("%d", &n);

    while (n--) {
        scanf("%d %d", &v, &e);

        memset(visitado, 0, sizeof(visitado));
        memset(matrizAdjacencia, 0, sizeof(matrizAdjacencia));

        for (i = 0; i < e; ++i) {
            scanf("%d %d", &verticeOrigem, &verticeDestino); 
            matrizAdjacencia[verticeOrigem][verticeDestino] = true;
        }
        printf("Caso %d:\n", ++caso);

        for (i = 0; i < v; ++i) {
            espaco[0] = 0;
            flag = false;

            if (!visitado[i]) {
                buscaProfundidade(i);
            }
            if (flag) {
                printf("\n");
            }
        }
    }

    return 0;
}
