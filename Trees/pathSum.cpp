#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(TreeNode* root, int targetSum,int currSum)
    {
        if(root ==NULL) return false;

        currSum += root->val;
        if(root->left == NULL && root->right == NULL && currSum == targetSum) return true;
        bool left =  dfs(root->left,targetSum, currSum);
        bool right = dfs(root->right, targetSum, currSum);

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum,0);
    }
};