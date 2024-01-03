#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// dsu + krushkal's algo
	unordered_map<int, int> parent, size;
    int findParent(int child) {
        if (parent[child] == child)
            return child;
        return parent[child] = findParent(parent[child]);
    }
    bool unionSet(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        sort(connections.begin(), connections.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int minCost = 0;
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (unionSet(u, v)) {
                minCost += w;
            }
        }
        unordered_set<int> representatives;
        for (int i = 1; i <= n; i++) {
            representatives.insert(findParent(i));
        }
        if (representatives.size() > 1)
            return -1;
        return minCost;
    }
};

int main(){
    
    return 0;
}