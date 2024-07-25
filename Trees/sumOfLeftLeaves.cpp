#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum =0;
    void solve(TreeNode* root, TreeNode* parent)
    {
        if(!root) return;

        if(root->left == NULL && root->right == NULL)
        {
            if(parent != NULL && parent->left == root)
            {
                sum+= root->val;
            }
        }
        solve(root->left,root);
        solve(root->right,root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,NULL);
        return sum;
    }
};