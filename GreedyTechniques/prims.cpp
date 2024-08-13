#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

int main() {
    int V = 4, E = 5;
    std::vector<std::vector<Edge>> graph(V);
    graph[0].push_back({0, 1, 2});
    graph[0].push_back({0, 2, 3});
    graph[1].push_back({1, 0, 2});
    graph[1].push_back({1, 2, 4});
    graph[1].push_back({1, 3, 2});
    graph[2].push_back({2, 0, 3});
    graph[2].push_back({2, 1, 4});
    graph[2].push_back({2, 3, 5});
    graph[3].push_back({3, 1, 2});
    graph[3].push_back({3, 2, 5});

    std::priority_queue<Edge> pq;
    std::vector<bool> inMST(V, false);

    int startingVertex = 0;
    inMST[startingVertex] = true;
    for (const Edge& edge : graph[startingVertex]) {
        pq.push(edge);
    }

    std::vector<Edge> mst;
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        int dest = edge.dest;

        if (!inMST[dest]) {
            mst.push_back(edge);
            inMST[dest] = true;

            for (const Edge& newEdge : graph[dest]) {
                if (!inMST[newEdge.dest]) {
                    pq.push(newEdge);
                }
            }
        }
    }

    std::cout << "Minimum Spanning Tree Edges:" << std::endl;
    for (const Edge& edge : mst) {
        std::cout << edge.src << " - " << edge.dest << " : " << edge.weight << std::endl;
    }

    return 0;
}
