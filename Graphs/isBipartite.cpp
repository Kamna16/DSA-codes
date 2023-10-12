#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> visited;
    bool isBipartite = true;
    
    void dfs(int src, vector<vector<int>>& graph, int color) {
        visited[src] = color;
        for (int neighbour : graph[src]) {
            if (visited[neighbour] == -1) {
                dfs(neighbour, graph, 1 - color);
            } else if (visited[neighbour] == color) {
                isBipartite = false;
                return;
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                dfs(i, graph, 1); // 0 and 1 denotes some colour
            }
        }
        
        return isBipartite;
    }
};

int main(){
    
    return 0;
}