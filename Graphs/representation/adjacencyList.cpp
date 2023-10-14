#include <iostream>
#include <list>
#include <vector>
using namespace std;

class GraphAdjacencyList {
    int vertices;
    vector<list<int>> adjacencyList;

public:
    GraphAdjacencyList(int vertices) {
        this->vertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source); // For undirected graphs
    }

    void displayGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << " --> ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    GraphAdjacencyList graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.displayGraph();

    return 0;
}
