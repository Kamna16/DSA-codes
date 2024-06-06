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
    bool isValid(TreeNode* root, long long min,long long max)
    {
        if(root == NULL) return true;
        if(root->val >= max || root->val <= min) return false;
        return isValid(root->left,min,root->val) && isValid(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return isValid(root,LLONG_MIN, LLONG_MAX);
    }
};
class Solution {
public:
    vector<int> inorder;
    void inorderTraversal(TreeNode* root)
    {
        if(root == NULL) return;
        
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorderTraversal(root);
        int n = inorder.size();
        for(int i=1;i<n;i++)
        {
            if(inorder[i] <= inorder[i-1]) return false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}