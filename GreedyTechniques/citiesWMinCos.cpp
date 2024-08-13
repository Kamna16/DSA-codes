#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> parent,rank;
	int find(int x)
	{
		if(parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void unionSets(int x, int y)
	{
		int Xparent = find(x);
		int Yparent = find(y);

		if(rank[Xparent] > rank[Yparent])
		{
			parent[Yparent] = Xparent;
			rank[Xparent]++;
		}
		else{
			parent[Xparent] = Yparent;
			rank[Yparent]++;
		}
	}
	int minimumCost(int n, vector<vector<int>>& connections) {
		for(auto &a : connections)
		{
			swap(a[2], a[0]);
		}
		parent.resize(n+1);
		rank.resize(n+1);
		for(int i=0;i<=n;i++)
		{
			parent[i] =i;
		}
		int totalMinCost =0;
		int remEdges = n-1;
		sort(connections.begin(), connections.end());
		for(auto &a:connections)
		{
			int Xparent = find(a[2]);
			int Yparent = find(a[1]);
			if(Xparent == Yparent) continue;
			totalMinCost += a[0];
			unionSets(a[1], a[2]);
			remEdges--;
			if(remEdges ==0) break;
		}
		if(remEdges != 0) return -1;

		return totalMinCost;
	}
}; 
int main(){
    
    return 0;
}