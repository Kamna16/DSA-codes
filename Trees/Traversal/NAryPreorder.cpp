#include<bits/stdc++.h>
using namespace std;

class NArrayTreeNode {
    public:
        int data;
        std::vector < NArrayTreeNode* > children;
    
        NArrayTreeNode() {
        }
        
        NArrayTreeNode(int data) {
            this->data = data;
        }
        
        NArrayTreeNode(int data, std::vector < NArrayTreeNode* > children) {
            this->data = data;
            this->children = children;
        }
};

class Solution {
public:
    vector<int> ans;
    void helper(NArrayTreeNode* & root)
    {
        // base case
        if(root == NULL) return;
        ans.push_back(root->data);
        // recursive case
        for(int i=0;i<root->children.size();i++)
        {
            helper(root->children[i]);
        }
        // post order 
        // first children will be visited then the node
    }
	vector<int> preorder(NArrayTreeNode* & root) {
		helper(root);
        return ans;
	}
};

int main(){
    
    return 0;
}