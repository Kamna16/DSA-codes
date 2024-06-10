#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	stack<int> st;
	vector<bool> visited;
	void dfs(vector<int> adj[],int u)
	{
	    visited[u] = true;
	    for(int & v : adj[u])
	    {
	        if(!visited[v]) dfs(adj,v);
	    }
	    st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    visited.resize(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(adj,i);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        int node = st.top();
	        ans.push_back(node);
	        st.pop();
	    }
	    return ans;
	}
};
