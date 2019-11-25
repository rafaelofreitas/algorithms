/*
   A busca em largura começa por um vértice, digamos v, especificado pelo usuário.
   O algoritmo visita v, depois visita todos os vizinhos de v, depois todos os vizinhos
   dos vizinhos, e assim por diante.

   O algoritmo numera os vértices, em sequência, na ordem em que eles são descobertos
   (ou seja, visitados pela primeira vez).  Para fazer isso, o algoritmo usa uma
   fila (= queue) de vértices.  No começo de cada iteração, a fila contém vértices
   que já foram numerados mas têm vizinhos ainda não numerados.

   O processo iterativo consiste no seguinte:

   enquanto a fila não estiver vazia
      retire um vértice v da fila
      para cada vizinho w de v
          se w não está numerado
              então numere w
                  ponha w na fila

   No começo da primeira iteração, a fila contém o vértice v, com número 0, e nada mais.
 */
#include <iostream>
#include <list>
#include <queue>

using namespace std;
// BFS search
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
// do width search from a point that will be the root
void bfs(int v);
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

void Graph::bfs(int v) {
        queue<int> queue;
        // visited vector
        bool visited[n];
        // mark all as unvisited
        for(int i = 0; i < v; i++) {
                visited[i] = false;
        }

        cout << "Visitando vertice: " << v << " ...\n";
        visited[v] = true;

        while(true) {
                list<int>::const_iterator itr = adj[v].begin();
                // search for an unvisited neighbor
                for(itr; itr != adj[v].end(); itr++) {
                        if(!visited[*itr]) {
                                cout << "Visitando vertice: " << *itr << " ...\n";
                                // mark as visited
                                visited[*itr] = true;
                                // insert in queue
                                queue.push(*itr);
                        }
                }
                // check if the queue is not empty
                if(!fila.empty()) {
                        // get first element of queue
                        v = queue.front();
                        // remove from queue
                        queue.pop();
                } else {
                        break;
                }
        }
}

int main(int argc, char *argv[]){
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

        graph.bfs(0);

        return 0;
}
