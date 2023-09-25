#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM 35

bool visitados[TAM];
char matrizAdjacencia[TAM][TAM];
char vertices[TAM];
int tamanhoAtual;
int v, e;

void buscaProfundidade(int vertice) {
    int i;
    visitados[vertice] = true;
    vertices[tamanhoAtual++] = vertice;
    
    for (i = 0; i < v; ++i) {
        if (matrizAdjacencia[vertice][i]) {
            if (!visitados[i]) {
                buscaProfundidade(i);
            }
        }
    }
}

int compara(char *a, char *b) {
    if (*a == *b) {
        return 0;
    } else if (*a > *b) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    char a, b;
    int i, j, casos;
    int caso = 0;

    scanf("%d", &casos);

    while (casos--) {
        scanf("%d %d", &v, &e);

        for (i = 0; i < e; ++i) {
            scanf(" %c %c", &a, &b);

            matrizAdjacencia[a - 'a'][b - 'a'] = 1;
            matrizAdjacencia[b - 'a'][a - 'a'] = 1;
        }
        printf("Case #%d:\n", ++caso);
        int componentesConectados = 0;

        for (i = 0; i < v; ++i) {
            if (!visitados[i]) {
                ++componentesConectados;
                buscaProfundidade(i);
                qsort(vertices, tamanhoAtual, sizeof(char), compara);
                
                for (j = 0; j < tamanhoAtual; ++j) {
                    printf("%c,", vertices[j] + 'a');
                }
                printf("\n");
            }

            tamanhoAtual = 0;
        }
        printf("%d connected components\n", componentesConectados);
        printf("\n");

        memset(visitados, false, sizeof(visitados));
        memset(matrizAdjacencia, 0, sizeof(matrizAdjacencia));
    }

    return 0;
}

