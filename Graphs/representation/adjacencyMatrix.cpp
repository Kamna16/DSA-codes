#include <iostream>
#include <cstring>
using namespace std;

class AdjacencyMatrix {
    int** matrix;
    int vertices;

public:
    AdjacencyMatrix(int vertices) {
        this->vertices = vertices;
        matrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            matrix[i] = new int[vertices];
            memset(matrix[i], 0, vertices * sizeof(int));
        }
    }

    void addEdge(int source, int destination) {
        matrix[source][destination] = 1;
        matrix[destination][source] = 1; // For undirected graphs
    }

    void displayMatrix() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    AdjacencyMatrix graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.displayMatrix();

    return 0;
}
