#include <iostream>
#include <vector>
using namespace std;

class InwardAdjacencyList {
    vector<vector<int>> inwardEdges;
    int vertices;

public:
    InwardAdjacencyList(int vertices) {
        this->vertices = vertices;
        inwardEdges.resize(vertices);
    }

    void addEdge(int source, int destination) {
        inwardEdges[destination].push_back(source);
    }

    void displayInwardEdges() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << " <-- ";
            for (int edge : inwardEdges[i]) {
                cout << edge << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    InwardAdjacencyList graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 1);
    graph.addEdge(3, 2);
    graph.addEdge(4, 3);

    graph.displayInwardEdges();

    return 0;
}
