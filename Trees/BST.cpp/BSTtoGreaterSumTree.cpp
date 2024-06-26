#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum =0;
    void Solve(TreeNode *root)
    {
        if(!root) return;
        Solve(root->right);
        sum += root->val;
        root->val = sum ;
        Solve(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        Solve(root);
        return root;
    }
};