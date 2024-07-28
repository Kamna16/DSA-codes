#include<bits/stdc++.h>
using namespace std;

// using priority Queue
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,S});
        dist[S] = 0;
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &n : adj[node])
            {
                int adjNode = n[0];
                int cost = n[1];
                if(d+cost < dist[adjNode])
                {
                    dist[adjNode] = d+cost;
                    pq.push({d+cost,adjNode});
                }
            }
        }
        return dist;
    }
};

// using Set--> better
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int,int>> st;
        st.insert({0,S});
        dist[S] = 0;
        while(!st.empty())
        {
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(it);
            for(auto &n : adj[node])
            {
                int adjNode = n[0];
                int cost = n[1];
                
                if(d+cost < dist[adjNode])
                {
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = d+cost;
                    st.insert({d+cost,adjNode});
                }
            }
        }
        return dist;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
