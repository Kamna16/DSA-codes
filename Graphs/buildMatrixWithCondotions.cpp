#include<bits/stdc++.h>
using namespace std;

// using topological sort
class Solution {
public:
    stack<int> st;
    vector<int> visited;

    void dfs(unordered_map<int,vector<int>> &adj, int u, bool &cycle) {
        visited[u] = 1;
        for (int &v : adj[u]) {
            if (visited[v] == 0) {
                dfs(adj, v, cycle);
                if (cycle) return; 
            } else if (visited[v] == 1) {
                cycle = true;
                return;
            }
        }
        visited[u] = 2; 
        st.push(u);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        visited.assign(V + 1, 0);
        bool cycle = false;
        
        for (int i = 1; i <= V; ++i) {
            if (visited[i] == 0) {
                dfs(adj, i, cycle);
                if (cycle) return {}; 
            }
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topo1 = topoSort(k, rowConditions);

        if (topo1.empty()) return {};

        visited.assign(k + 1, 0);
        while (!st.empty()) st.pop();

        vector<int> topo2 = topoSort(k, colConditions);

        if (topo2.empty()) return {};

        vector<vector<int>> ans(k, vector<int>(k, 0));
        unordered_map<int, int> rowPos, colPos;

        for (int i = 0; i < k; ++i) {
            rowPos[topo1[i]] = i;
            colPos[topo2[i]] = i;
        }

        for (int i = 1; i <= k; ++i) {
            ans[rowPos[i]][colPos[i]] = i;
        }

        return ans;
    }
};
