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
int counter = 0;
    int kthElement =0;
    void inorder(TreeNode* & root, int k)
    {
        if(root == NULL) return;

        inorder(root->left,k);
        counter++;

        if(counter == k) kthElement = root->data;

        inorder(root->right,k);
    }
	int kthSmallest(TreeNode* & root, int k) {
		inorder(root,k);
        return kthElement;
	}
};

int main(){
    
    return 0;
}