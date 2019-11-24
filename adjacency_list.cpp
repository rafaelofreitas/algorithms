/*
   Em teoria dos grafos, uma lista de adjacência, estrutura de adjacência
   ou dicionário é a representação de todas arestas ou arcos de um grafo em uma lista.
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

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
// get the degree of output of a vertex data
// degree of output is the number of arcs coming out of "v"
int get_out_degree(int v);
// vertice if v2 is neighbor of v1
bool there_neighbor(int v1, int v2);
};

Graph::Graph(int v){
        // assign the number of vertices
        this->n = v;
        // create lists
        adj = new list<int>[n];
}

void Graph::add_edge(int v1, int v2){
        // add vertex v2 to the list of adjacent vertices of v1
        adj[v1].push_back(v2);
}

int Graph::get_out_degree(int v){
        // list size which is the amount of neighbors
        return adj[v].size();
}

bool Graph::there_neighbor(int v1, int v2){
        // looking for vertex neighbors
        if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) {
                return true;
        }

        return false;
}

int main(int argc, char *argv[]){
        // creating a 4-vertex graph
        Graph graph(4);

        // adding the edges
        graph.add_edge(0, 1);
        graph.add_edge(0, 3);
        graph.add_edge(1, 2);
        graph.add_edge(3, 1);
        graph.add_edge(3, 2);

        // showing degrees of output
        cout << "Grau de saida do vertice 1: " << graph.get_out_degree(1);
        cout << "\nGrau de saida do vertice 3: " << graph.get_out_degree(3);

        // checking for neighbors
        if(graph.there_neighbor(0, 1)) {
                cout << "\n\n1 eh vizinho de 0 \n";
        } else {
                cout << "\n\n1 nao eh vizinho de 0\n";
        }

        // checking for neighbors
        if(graph.there_neighbor(0, 2)) {
                cout << "2 eh vizinho de 0 \n";
        } else {
                cout << "2 nao eh vizinho de 0\n";
        }

        return 0;
}
