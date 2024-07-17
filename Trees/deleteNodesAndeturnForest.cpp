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
    vector<TreeNode*> forest;
    TreeNode* solve(TreeNode* root, vector<int>& to_delete)
    {
        if(!root) return NULL;

        root->left = solve(root->left, to_delete);
        root->right = solve(root->right, to_delete);
        if(find(to_delete.begin(),to_delete.end(),root->val) != to_delete.end())
        {
            if(root->left != NULL) forest.push_back(root->left);
            if(root->right != NULL) forest.push_back(root->right);
            return NULL; // delete
        }
        return root;//else
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(find(to_delete.begin(),to_delete.end(),root->val) == to_delete.end()) // don't have to delete root
            forest.push_back(root);
        solve(root,to_delete);
        return forest;
    }
};