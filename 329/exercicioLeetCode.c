//Defindo uma matriz 4x2 na qual cada par representa uma direcao em que pode se mover na matriz.
int direcao[4][2] = {
    {1,0},  //Direita.
    {-1,0}, //Esquerda.
    {0,1},  //Baixo.
    {0,-1}  //Cima.
};

//Funcao para a busca em profundidade.
//matriz -> matriz original.
//comprimento -> matriz que armazena os comprimentos dos caminhos mais longos.
//m -> numero de linhas da matriz.
//n -> numero de colunas da matriz.
//r, c -> coordenadas do nó atual na matriz.
int dfs(int **matriz, int **comprimento, int m, int *n, int r, int c) {

    //verifica se ja foi calculado e armazena.
    if(comprimento[r][c]) return comprimento[r][c];

    int max_c = 1;

    //Percorre as 4 direcoes possiveis e verifica se pode se mover para um nó vizinho.
    for(int i=0; i<4; i++) {

        //Armazenam a coordenada da próxima linha e coluna que o algoritmo está prestes a verificar. 
        //Ela é calculada adicionando ou subtraindo 1 da coordenada atual.
        int next_r = r + direcao[i][0];
        int next_c = c + direcao[i][1];

        /*Verifica se a proxima linha ou coluna esta dentro dos limites da matriz.
        matriz[next_r][next_c] > matriz[r][c]: Este teste verifica se o valor na 
        próxima célula é estritamente maior do que o valor do nó atual.*/
        if(next_r < m && next_r >= 0 && next_c < n[next_r] && next_c >= 0 && matriz[next_r][next_c] > matriz[r][c]) {

            /*Chama recursivamente a função dfs para explorar o caminho
            a partir do nó vizinho. Adiciona 1 ao resultado retornado 
            por dfs porque estamos considerando o nó vizinho,
            aumentando assim o comprimento do caminho em 1.*/
            int count = dfs(matriz, comprimento, m, n, next_r, next_c) + 1;

            //Atualizar o valor maximo do comprimento encontrado.
            if(max_c < count) max_c = count;
        }
    }

    comprimento[r][c] = max_c;

    return max_c;
}

//Principal função para calcular o comprimento do caminho mais longo de valores crescentes da matriz. 
int longestIncreasingPath(int **matriz, int matrizSize, int *matrizColSize) {

    /*Aloca dinamicamente memória para a matriz, para armazenar os comprimentos 
    dos caminhos mais longos a partir de cada nó da matriz original.*/
    int **comprimento = malloc(matrizSize*sizeof(int *));

    //Aloca memória para cada linha da matriz 'comprimento' e usa a função memset para inicializar todos os valores com zero.
    for(int i=0; i<matrizSize; i++) {

        comprimento[i] = malloc(matrizColSize[i]*sizeof(int));
        memset(comprimento[i], 0, matrizColSize[i]*sizeof(int));
    }

    int resultado = 0;

    //Percorre todos os nós da matriz original.
    /*Para cada nó chama o dfs para calcular o comprimento maximo do caminho a partir
    do nó e se o comprimento maximo encontrado for maior que o atual, atualiza.*/
    for(int i=0; i<matrizSize; i++) {
        for(int j=0; j<matrizColSize[i]; j++) {

            int temporaria = dfs(matriz, comprimento, matrizSize, matrizColSize, i, j);

            //Atualiza o valor do comprimento maximo do caminho.
            if(resultado < temporaria) {
                resultado = temporaria;
            }
        }
    }

    return resultado;
}