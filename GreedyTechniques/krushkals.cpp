#include <iostream>
#include <algorithm>
#include <vector>

struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int findParent(std::vector<int>& parent, int v) {
    if (parent[v] == -1)
        return v;
    return findParent(parent, parent[v]);
}

void unionSets(std::vector<int>& parent, int x, int y) {
    int xParent = findParent(parent, x);
    int yParent = findParent(parent, y);
    parent[xParent] = yParent;
}

int main() {
    int V = 4, E = 5;
    std::vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 4},
        {1, 3, 2},
        {2, 3, 5}
    };

    std::sort(edges.begin(), edges.end());

    std::vector<int> parent(V, -1);
    std::vector<Edge> mst;

    for (const Edge& edge : edges) {
        int srcParent = findParent(parent, edge.src);
        int destParent = findParent(parent, edge.dest);

        if (srcParent != destParent) {
            mst.push_back(edge);
            unionSets(parent, srcParent, destParent);
        }
    }

    std::cout << "Minimum Cost Spanning Tree Edges:" << std::endl;
    for (const Edge& edge : mst) {
        std::cout << edge.src << " - " << edge.dest << " : " << edge.weight << std::endl;
    }

    return 0;
}
