#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 35

bool visitados[MAXSIZE];
char matrizAdjacencia[MAXSIZE][MAXSIZE];
char vertices[MAXSIZE];
int tam;
int m, n;

void buscaProfundidade(int vertice) {
    int i;
    visitados[vertice] = true;
    vertices[tam++] = vertice;
    
    for (i = 0; i < m; ++i) {
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
        scanf("%d %d", &m, &n);

        for (i = 0; i < n; ++i) {
            scanf(" %c %c", &a, &b);

            matrizAdjacencia[a - 'a'][b - 'a'] = 1;
            matrizAdjacencia[b - 'a'][a - 'a'] = 1;
        }
        printf("Case #%d:\n", ++caso);
        int ans = 0;

        for (i = 0; i < m; ++i) {
            if (!visitados[i]) {
                ++ans, buscaProfundidade(i);
                qsort(vertices, tam, sizeof(char), compara);

                for (j = 0; j < tam; ++j) {
                    printf("%c,", vertices[j] + 'a');
                }
                printf("\n");
            }

            tam = 0;
        }
        printf("%d connected components\n", ans);
        printf("\n");

        memset(visitados, false, sizeof(visitados));
        memset(matrizAdjacencia, 0, sizeof(matrizAdjacencia));
    }

    return 0;
}

