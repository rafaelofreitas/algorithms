/*
   Em termos um tanto vagos, um ciclo em um grafo é um caminho fechado sem vértices
   repetidos. Mais precisamente, um ciclo (= cycle) é um caminho
   (v0, a1, v1, a2, v2, . . . , ak, vk)  com k > 1 onde

   vk = v0  mas v0,  v1,  v2,  . . . ,  vk–1  são distintos dois a dois.
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
bool dfs(int v);
// check if the graph has any cycles
bool have_cycle();
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

bool Graph::dfs(int v) {
        stack<int> stack;
        // visited vector
        bool visited[n], stack_rec[n];
        // mark all as unvisited
        for(int i = 0; i < v; i++) {
                visited[i] = stack_rec[i] = false;
        }

        while(true) {
                if(!visited[v]) {
                        // mark as visited
                        visited[v] = stack_rec[v] = true;
                        // insert "v" in the stack
                        stack.push(v);
                }

                bool found = false;
                list<int>::const_iterator itr = adj[v].begin();
                // search for an unvisited neighbor
                for(itr; itr != adj[v].end(); itr++) {
                        // if the neighbor is in the stack is because there is already cycle
                        if(stack_rec[*itr]) {
                                return true;
                        } else if(!visited[*itr]) {
                                // if it is not in the stack and has not been visited, indicates that you found
                                found = true;
                                break;
                        }
                }

                if(!found) {
                        // mark that came out of the stack
                        stack_rec[stack.top()] = false;
                        // remove from stack
                        stack.pop();

                        if(stack.empty()) {
                                break;
                        }

                        v = stack.top();
                } else {
                        v = *itr;
                }
        }

        return false;
}

bool Graph::have_cycle() {
        for(int i = 0; i< n; i++) {
                if(dfs(i)) {
                        return true;
                }
        }

        return false;
}

int main(int argc, char *argv[]){
        // creating a 8-vertex graph
        Graph graph(8);
        // adding the edges
        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(1, 3);
        graph.add_edge(3, 0);

        if(graph.have_cycle()) {
                cout << "Contem ciclo!\n";
        } else {
                cout << "Nao contem ciclo!\n";
        }

        return 0;
}
