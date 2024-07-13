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
   vector<int> inorder;
    void dfs(TreeNode* root)
    {
        if(root == NULL) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int mini=INT_MAX;
        for(int i=1;i<inorder.size();i++)
        {
            mini = min(mini,inorder[i]-inorder[i-1]);
        }
        return mini;
    }
};

// using no space
class Solution {
public:
    int mini=INT_MAX;
    void dfs(TreeNode* root,TreeNode* prev)
    {
        if(root == NULL) return;
        dfs(root->left,prev);
        if(prev != NULL) mini = min(mini, root->val - prev->val);
        dfs(root->right,root);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        dfs(root,prev);
        return mini;
    }
};