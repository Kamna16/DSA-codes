#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Solution {
public:
    int count=0;
    void sum(TreeNode* root, int low, int high)
    {
        if(root == NULL) return;

        sum(root->left,low,high);
        if(root->val >= low && root->val <= high) count += root->val;
        sum(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum(root,low,high);
        return count;
    }
};

// using bst property
class Solution {
public:
    int count=0;
    void sum(TreeNode* root, int low, int high)
    {
        if(root == NULL) return;

        if(root->val >= low) sum(root->left,low,high);
    
        if(root->val >= low && root->val <= high) count += root->val;

        if(root->val <= high) sum(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum(root,low,high);
        return count;
    }
};