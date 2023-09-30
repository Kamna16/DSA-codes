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
    bool isTreeBalanced = true;
    int height(TreeNode* & root)
    {
        if(root == NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(abs(rightHeight-leftHeight) > 1) isTreeBalanced = false;

        int currHeight = max(leftHeight, rightHeight) +1;

        return currHeight;
    }
	bool isBalanced(TreeNode* & root) 
    {
		height(root);
        return isTreeBalanced;
	}
};

int main(){
    
    return 0;
}