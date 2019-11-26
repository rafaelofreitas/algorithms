/*
   Implementação do algoritmo de Kruskal

   O algoritmo de Kruskal é um algoritmo em teoria dos grafos que busca uma árvore
   geradora mínima para um grafo conexo com pesos. Isto significa que ele encontra
   um subconjunto das arestas que forma uma árvore que inclui todos os vértices,
   onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado.

   Para detectar ciclos estou utilizando o algoritmo Union-Find, para detecção
   dos ciclos em grafos não direcionados.

 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
// defining class that has the edge weight and the vertices that connect
class Edge {
int vertex1, vertex2, weight;
// Edge class builder
public:
Edge(int vertex1, int vertex2, int weight) {
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->weight = weight;
}
// returns vertex
int get_vertex1() {
        return vertex1;
}
// returns vertex
int get_vertex2() {
        return vertex2;
}
// returns weight
int get_weight() {
        return weight;
}
// operator override "<"
bool operator < (const Edge& edge2) const {
        return (weight < edge2.weight);
}
};

class Graph {
int vertex_number;
vector<Edge> edges;

public:
Graph(int vertex_number) {
        this->vertex_number = vertex_number;
}
// add an edge to the graph
void add_edges(int vertex1, int vertex2, int weight){
        Edge edge(vertex1, vertex2, weight);
        edges.push_back(edge);
}
// function that fetches the subset of a "i" element
int find(int subset[], int i) {
        if(subset[i] == -1) {
                return i;
        }

        return find(subset, subset[i]);
}
// function to join two subsets into one set
void _union(int subset[], int vertex1, int vertex2) {
        int vertex1_set = find(subset, vertex1);
        int vertex2_set = find(subset, vertex2);

        subset[vertex1_set] = vertex2_set;
}
// function that runs Kruskal algorithm
void kruskal() {
        vector<Edge> tree;
        int size_edges = edges.size();
        // sort edges by smallest get_weight
        sort(edges.begin(), edges.end());
        // allocate memory to create "vertex number" subsets
        int* subset = new int[vertex_number];
        // initializes all subsets as single element sets
        memset(subset, -1, sizeof(int) * vertex_number);

        for(int i = 0; i < size_edges; i++) {
                int vertex1 = find(subset, edges[i].get_vertex1());
                int vertex2 = find(subset, edges[i].get_vertex2());
                // if they are different it is because they do not cycle, insert into the vector
                if(vertex1 != vertex2) {
                        tree.push_back(edges[i]);
                        // make the union
                        _union(subset, vertex1, vertex2);
                }
        }

        int size_tree = tree.size();
        // show selected edges with their respective weights
        for(int i = 0; i < size_tree; i++) {
                char vertex1 =  'A' + tree[i].get_vertex1();
                char vertex2 =  'A' + tree[i].get_vertex2();
                cout << "(" << vertex1 << ", " << vertex2 << ") = " << tree[i].get_weight() << endl;
        }
}
};

int main(int argc, char *argv[]) {
        // building a graph that has 7 vertex
        Graph graph(7);
        // adding all vertex connections and their respective weights
        graph.add_edges(0, 1, 7);
        graph.add_edges(0, 3, 5);
        graph.add_edges(1, 2, 8);
        graph.add_edges(1, 3, 9);
        graph.add_edges(1, 4, 7);
        graph.add_edges(2, 4, 5);
        graph.add_edges(3, 4, 15);
        graph.add_edges(3, 5, 6);
        graph.add_edges(4, 5, 8);
        graph.add_edges(4, 6, 9);
        graph.add_edges(5, 6, 11);
        // run the kruskal algorithm
        graph.kruskal();

        return 0;
}
