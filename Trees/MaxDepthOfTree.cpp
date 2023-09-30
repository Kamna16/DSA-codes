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
	int maxDepth(TreeNode* & root) {
        if(root == NULL) return 0;
		int heightLeft = maxDepth(root->left);
		int heightRight = maxDepth(root->right);
        return max(heightLeft,heightRight) +1;

	}
};

int main(){
    
    return 0;
}