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
int diameter = 0;
    int helper( TreeNode* & root)
    {
        if(root == NULL) return 0;
        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);

        int currHeight  = max(leftHeight,rightHeight) + 1;

        diameter = max(diameter, leftHeight +  rightHeight);
        return currHeight;
    }
	int diameterOfBinaryTree(TreeNode* & root) {
        helper(root);
		return diameter;
	}
};

int main(){
    
    return 0;
}