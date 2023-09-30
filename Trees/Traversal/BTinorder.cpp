#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode() {
        }
        
        TreeNode(int data) {
            this->data = data;
        }
        
        TreeNode(int data, TreeNode* left, TreeNode* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

class Solution {
public:
    void helper(TreeNode * &root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        helper(root->left,ans);
        ans.push_back(root->data);
        helper(root->right,ans);
    }
	vector<int> inorderTraversal(TreeNode* & root) {
		vector<int> ans;
        helper(root,ans);
        return ans;
	}
};

int main(){
    
    return 0;
}