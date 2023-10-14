#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int source;
    int destination;

    Edge(int source, int destination) {
        this->source = source;
        this->destination = destination;
    }
};

class GraphEdgeList {
    vector<Edge> edges;

public:
    void addEdge(int source, int destination) {
        Edge edge(source, destination);
        edges.push_back(edge);
    }

    void displayEdges() {
        for (Edge edge : edges) {
            cout << "Edge: " << edge.source << " -> " << edge.destination << endl;
        }
    }
};

int main() {
    GraphEdgeList graph;

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.displayEdges();

    return 0;
}
