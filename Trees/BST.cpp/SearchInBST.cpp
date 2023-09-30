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
    bool isPresent = false;
    void search(TreeNode* & root, int val)
    {
        if(root == NULL) return;
        if(root->data == val) isPresent=true;
        if(root->data < val) 
        {
            search(root->right,val);
        }
        if(root->data > val)
        {
            search(root->left,val);
        }
        return;
    }
	bool searchBST(TreeNode* & root, int val) {
		search(root,val);
        return isPresent;
	}
};

int main(){
    
    return 0;
}