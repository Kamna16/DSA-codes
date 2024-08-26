#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>> &adj,int i, vector<bool> &visited)
    {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            
            for (int &neighbour : adj[top]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;  // Mark as visited here
                    q.push(neighbour);  // Push into the queue
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       vector<vector<int>> adj(n);
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(isConnected[i][j] == 1)
               {
                   adj[i].push_back(j);
                   adj[j].push_back(i);
               }
           }
       } 
       vector<bool> visited(n,false);
       int count=0;
       for(int i=0;i<n;i++)
       {
           if(!visited[i])
           {
               bfs(adj,i,visited);
               count++;
           }
       }
       return count;
    }
};