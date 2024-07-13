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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        if(root == p || root == q) return root;

        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);

        if(left != NULL && right != NULL) return root;
        if(left != NULL) return left;
        return right;
    }
};