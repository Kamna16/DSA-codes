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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        bool isValSame = p->val == q->val ? true : false;
        return left && right && isValSame;
    }
};

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p,q);
    }
};
