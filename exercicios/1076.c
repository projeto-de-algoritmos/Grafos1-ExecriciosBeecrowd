#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define TAM 110

//Declaração da função dfs.
void dfs(int);

int visitados[TAM]; //Usado para marcar os nós que já foram visitados durante o DFS.
char matriz[TAM][TAM]; //Matriz que representa um grafo não direcionado.

int totalNo, contador;

int main(int argc, char **argv) {
    int numCasosTeste, numArestas;
    int noInicial, a, v; //'a' e 'v' representam nós conectados por uma aresta.

    scanf("%d", &numCasosTeste);

    while (numCasosTeste--) {
        scanf("%d", &noInicial);
        scanf("%d %d", &totalNo, &numArestas);

        //Reinicia 'visitados' e 'matriz' com 0.
        memset(visitados, 0, sizeof(visitados));
        memset(matriz, 0, sizeof(matriz));

        for (int i = 0; i < numArestas; ++i) {

            //lê 'a' e 'v' e são preenchidos na matriz.
            scanf("%d %d", &a, &v);
            matriz[a][v] = matriz[v][a] = true;
        }

        contador = 0;
        dfs(noInicial);
        printf("%d\n", contador << 1);
    }

    return 0;
}

//Função de busca em profundidade (DFS) que é usada para percorrer o grafo
// e contar os nós alcancaveis a partir de um nó.
void dfs(int a) {

    visitados[a] = true;

    for (int i = 0; i < totalNo; ++i) {
        if (matriz[a][i]) {
            if (!visitados[i]) {
                dfs(i), contador++;
            }
        }
    }
}