#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int V, vector<int> adj[],int u,vector<bool> &vis,int parent)
    {
        vis[u] = true;
        for(int v : adj[u])
        {
            if(v == parent) continue;
            if(vis[v]) return true;
            if(dfs(V,adj,v,vis,u)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && dfs(V,adj,i,vis,-1)) return true;
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
