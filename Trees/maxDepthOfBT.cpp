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

// dfs
class Solution {
public:
    int minDepth(TreeNode* root) {
       if(root == NULL) return 0;
       if(root->left == NULL && root->right == NULL) return 1;
       int left = root->left ? minDepth(root->left) : INT_MAX;
       int right = root->right ? minDepth(root->right) : INT_MAX;
       return 1 + min(left,right);
    }
};

// bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
       if(root == NULL) return 0;
       queue<TreeNode*> q;
       q.push(root);
       int depth = 1;
       while(!q.empty())
       {
            int size = q.size();
           while(size--)
           {
             TreeNode* curr = q.front();
              q.pop();

              if(curr->left == NULL && curr->right == NULL) return depth;
              if(curr->left != NULL) q.push(curr->left);
              if(curr->right != NULL) q.push(curr->right);
           }
           depth++;
       }
       return -1;
    }
};

int main(){
    
    return 0;
}