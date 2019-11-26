/*
   Um algoritmo union-find é um algoritmo que realiza duas operações úteis nesta
   estrutura de dados:
      Find: Determina a qual conjunto um determinado elemento pertence.
      Também útil para determinar se dois elementos estão no mesmo conjunto.

      Union: Combina ou agrupa dois conjuntos em um único conjunto.

      Neste exemplo estou utilizando o union-find para saber, de maneira rápida,
      se dois vértices do grafo(= graph) estão no mesmo conjunto.
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
// function that fetches the subset of a "v" element
int find(int subset[], int v) {
        if(subset[v] == -1) {
                return v;
        }

        return find(subset, subset[v]);
}
// function to join two subsets into one set
void _union(int subset[], int v1, int v2) {
        int v1_set = find(subset, v1);
        int v2_set = find(subset, v2);

        subset[v1_set] = v2_set;
}
// function to check if the graph has a cycle
int have_cycle(int graph[3][3]) {
        int * subset = (int*)malloc(3 * sizeof(int));
        // initialize all subsets of a single element
        memset(subset, -1, sizeof(int) * 3);

        for(int i = 0; i < 3; i++) {
                for(int j = i; j < 3; j++) {
                        if(graph[i][j] == 1) {
                                int v1 = find(subset, i);
                                int v2 = find(subset, j);

                                if(v1 == v2) {
                                        return 1;
                                }

                                _union(subset, v1, v2);
                        }
                }
        }

        return 0;
}

int main(int argc, char *argv[]) {
        int graph[3][3] = {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
        };

        graph[0][1] = 1;
        graph[1][0] = 1;
        graph[1][2] = 1;
        graph[2][1] = 1;
        graph[0][2] = 1;
        graph[2][0] = 1;

        if(have_cycle(graph)) {
                cout << "O grafo tem ciclo!\n";
        } else {
                cout << "O grafo nao tem ciclo!\n";
        }

        return 0;
}
