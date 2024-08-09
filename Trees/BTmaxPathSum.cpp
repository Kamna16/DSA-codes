#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root)
    {
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);
        int gotAns_down = l+r+root->val;
        int anyOne_isGood = max(l,r)+root->val;
        int onlyRoot_isGood = root->val;

        maxSum = max({maxSum,gotAns_down, anyOne_isGood,onlyRoot_isGood});

        return max(anyOne_isGood, onlyRoot_isGood);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};