#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {
public:
    TreeNode* LCA(TreeNode* root,int p,int q)
    {
        if(!root) return NULL;
        if(root->val==p || root->val==q) return root;
        TreeNode* left = LCA(root->left,p,q);
        TreeNode* right = LCA(root->right,p,q);
        if(left != NULL && right != NULL) return root;
        if(left == NULL) return right;
        return left;
    }
    bool dfs(TreeNode* root, int target, string &path) {
        if (!root) return false;
        if (root->val == target) return true;

        path.push_back('L');
        if (dfs(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (dfs(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root,startValue,destValue);

        string LCAtoSrc = "";
        dfs(lca,startValue,LCAtoSrc);
        string LCAtoDest = "";
        dfs(lca,destValue,LCAtoDest);

        string result="";
        for(int i=0;i<LCAtoSrc.size();i++)
        {
            result += "U";
        }
        return result+LCAtoDest;

        int size = LCAtoSrc.size();
        string ans="";
        for(int i=0;i<size;i++)
        {
            ans+='U';
        }
        return ans+LCAtoDest;
    }
};