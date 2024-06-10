#include<bits/stdc++.h>
using namespace std;

// using DSU
class Solution {
public:
    vector<int> parent;
    int components;
    int findParent(int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionNodes(int P, int C)
    {
        // if already has parent
        if(findParent(C) != C) return false;

        // if parent's parent is child
        if(findParent(P) == C) return false;

        parent[C] = P;
        components -= 1;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        components = n;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            int node = i;
            int left_child = leftChild[i];
            int right_child = rightChild[i];

            if(left_child != -1 && unionNodes(node,left_child)==false) return false;
            if(right_child != -1 && unionNodes(node,right_child)==false) return false;
        }

        return components == 1;
    }
};

int main(){
    
    return 0;
}