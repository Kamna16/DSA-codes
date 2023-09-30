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
    int mini = INT_MAX;
    int prev =-1;
    void inorder(TreeNode* root)
    {
        if(root == NULL) return;
        inorder(root->left);
        if(prev == -1)
        {
            prev = root->data;
        }
        else{
            mini = min(root->data - prev, mini);
            prev = root->data;
        }
        inorder(root->right);
        return;
    }
	int minDiffInBST(TreeNode* & root) {
		if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        inorder(root);
        return mini;
	}
};

int main(){
    
    return 0;
}