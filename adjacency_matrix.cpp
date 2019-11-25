
/*
   Uma matriz de adjacência é uma das formas de se representar um grafo.
   Dado um grafo "graph" com n vértices, podemos representá-lo em uma
   matriz n x n A(graph)=[aij] (ou simplesmente A).

   A matriz de adjacências de um grafo é uma matriz de 0's e 1's com colunas
   e linhas indexadas pelos vértices.  Se  graph[][]  é uma tal matriz então,
   para cada vértice v e cada vértice w,

   graph[v][w] = 1   se v-w é um arco  e
   graph[v][w] = 0   em caso contrário.

   Assim, a linha v da matriz graph[][] representa o leque de saída do vértice v
   e a coluna w da matriz representa o leque de entrada do vértice w.
 */
#include <iostream>

using namespace std;

int graph[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}
};

bool have_connection(int v1, int v2) {
        if(graph[v1][v2]) {
                return true;
        }

        return false;
}

int main(int argc, char *argv[]) {
        cout << have_connection(0, 2) << endl;
        return 0;
}
