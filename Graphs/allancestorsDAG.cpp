#include<bits/stdc++.h>
using namespace std;

// Approach 1
class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj,int ancestor,vector<vector<int>> &ans)
    {
        for(int &neighbour : adj[u])
        {
            if(ans[neighbour].empty() || ans[neighbour].back() != ancestor) // avoid duplicate
            {
                ans[neighbour].push_back(ancestor);
                dfs(neighbour,adj,ancestor,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n); // o(V+E)
        for(vector<int> &edge : edges) // o(E)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++)// o(V)
        {
            int ancestor = i;
            dfs(i,adj,ancestor, ans); // o(V+E)
        }
        return ans;
    }
};

// Approach 2
class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj,vector<bool> &visited)
    {
        visited[u] = true;
        for(int &neighbour : adj[u])
        {
            if(visited[neighbour] != true)
            {
                dfs(neighbour,adj,visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        for(vector<int> &edge : edges)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        for(int u=0;u<n;u++)
        {
            vector<bool> visited(n,false);
            dfs(u,adj, visited);
            for(int j=0;j<n;j++)
            {
                if(j != u && visited[j])
                {
                    ans[u].push_back(j);
                }
            }
        }
        return ans;
    }
};