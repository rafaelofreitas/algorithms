/*
   Na teoria dos grafos, busca em profundidade (ou busca em profundidade-primeiro,
   também conhecido em inglês por Depth-First Search - DFS) é um algoritmo usado
   para realizar uma busca ou travessia numa árvore, estrutura de árvore ou grafo.
   Intuitivamente, o algoritmo começa num nó raiz (selecionando algum nó como sendo
   o raiz, no caso de um grafo) e explora tanto quanto possível cada um dos seus ramos,
   antes de retroceder(backtracking).

   A busca em profundidade iterativa procura combinar as
   virtudes da busca em profundidade e da busca em largura.
   São elas a relativamente pouca necessidade de memória e a
   capacidade de examinar todo o espaço de estados
   encontrando a solução ótima, respectivamente.
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;
// interactive DFS search
class Graph {
// vertex numbers
int n;
// pointer to an array containing the adjacency lists
list<int> *adj;
// graph builder
public:
Graph(int v);
// add an edge to the graph
void add_edge(int v1, int v2);
// do a deep search from a point that will be the root
void dfs(int v);
};

Graph::Graph(int v) {
        // assign the number of vertices
        this->n = v;
        // create lists
        adj = new list<int>[n];
}

void Graph::add_edge(int v1, int v2) {
        // add vertex v2 to the list of adjacent vertices of v1
        adj[v1].push_back(v2);
}

void Graph::dfs(int v) {
        stack<int> stack;
        // visited vector
        bool visited[n];
        // mark all as unvisited
        for(int i = 0; i < v; i++) {
                visited[i] = false;
        }

        while(true) {
                if(!visited[v]) {
                        cout << "Visitando vértice " << v << " ...\n";
                        // mark as visited
                        visited[v] = true;
                        // insert "v" in the stack
                        stack.push(v);
                }

                bool found = false;
                list<int>::const_iterator itr = adj[v].begin();
                // search for an unvisited neighbor
                for(itr; itr != adj[v].end(); itr++) {
                        if(!visited[*itr]) {
                                found = true;
                                break;
                        }
                }

                if(found) {
                        // update the "v"
                        v = *itr;
                } else {
                        // if all neighbors are visited or no neighbors
                        // remove from stack
                        stack.pop();
                        // if the stack is empty then the search is over
                        if(stack.empty()) {
                                break;
                        }
                        // if you got here, you can take the top element
                        v = stack.top();
                }
        }
}

int main(int argc, char *argv[]) {
        // creating a 8-vertex graph
        Graph graph(8);
        // adding the edges
        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(1, 3);
        graph.add_edge(1, 4);
        graph.add_edge(2, 5);
        graph.add_edge(2, 6);
        graph.add_edge(6, 7);

        graph.dfs(0);

        return 0;
}
