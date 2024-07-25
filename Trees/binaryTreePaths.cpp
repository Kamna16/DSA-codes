#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* root, string temp)
    {
        if (!root) return;

        if (!temp.empty()) {
            temp += "->";
        }
        temp += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        dfs(root->left, temp);
        dfs(root->right, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};