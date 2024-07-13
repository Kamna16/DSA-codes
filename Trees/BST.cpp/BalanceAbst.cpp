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
    vector<int> vec;
    void dfs(TreeNode* root)
    {
        if(!root) return;
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* solve(int l, int r)
    {
        if(l>r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = solve(l,mid-1);
        root->right = solve(mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* curr = root;
        dfs(root);
        int n = vec.size();
        return solve(0,n-1);
    }
};