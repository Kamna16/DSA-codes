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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> temp;
        dfs(root,targetSum,0,temp);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, int currSum, vector<int> &temp){
        if(!root) return;
        currSum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(currSum == targetSum) ans.push_back(temp);
            temp.pop_back();
            return;
        }

        dfs(root->left,targetSum,currSum,temp);
        dfs(root->right,targetSum,currSum,temp);
        temp.pop_back();
    }
};