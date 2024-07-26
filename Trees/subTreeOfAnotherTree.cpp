#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(TreeNode* p,TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        if(q == NULL || p == NULL) return false;
        if(p->val != q->val) return false;
        if(helper(p->left,q->left) == true && helper(p->right,q->right) == true) return true;
        else return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val == subRoot->val)
        {
            if(helper(root,subRoot)) return true;
        }
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        return left || right;
    }
};