#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode() {
            this->left = this->right = NULL;
        }
        
        TreeNode(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
        
        TreeNode(int data, TreeNode* left, TreeNode* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

class Solution {
public:
    vector<int> inorderOfTree;
    void inorder(TreeNode* & root)
    {
        if(root == NULL) return;

        inorder(root->left);
        inorderOfTree.push_back(root->data);
        inorder(root->right);

        return;
    }
	bool findTarget(TreeNode* & root, int k) {
		inorder(root);
        int n = inorderOfTree.size();
        int i=0;
        int j = n-1;
        while(i< j)
        {
            if(inorderOfTree[i] +inorderOfTree[j] == k) return true;
            else if(inorderOfTree[i] +inorderOfTree[j] < k)
            {
                i++;
            }
            else{
                j--;
            }
        }
        return false;
	}
};

int main(){
    
    return 0;
}