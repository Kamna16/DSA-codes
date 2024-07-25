#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool traversal(TreeNode* left, TreeNode* right)
    {
        if(left == NULL || right == NULL) return left==right;

        if(left->val != right->val) return false;
        return traversal(left->left, right->right) && traversal(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root== NULL || traversal(root->left, root->right);
    }
};