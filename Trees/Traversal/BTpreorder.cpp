#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode() {
        }
        
        TreeNode(int data) {
            this->data = data;
        }
        
        TreeNode(int data, TreeNode* left, TreeNode* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

class Solution {
public:
    void helper(TreeNode * &root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        ans.push_back(root->data);
        helper(root->left,ans);
        helper(root->right,ans);
    }
	vector<int> preorderTraversal(TreeNode* & root) {
		vector<int> ans;
        helper(root,ans);
        return ans;
	}
};


// iterative using stack
class Solution {
public:
    void helper(TreeNode * &root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        ans.push_back(root->data);
        helper(root->left,ans);
        helper(root->right,ans);
    }
	vector<int> preorderTraversal(TreeNode* & root) {
		stack<TreeNode*> s;
        vector<int> ans;

        s.push(root);

        while(!s.empty())
        {
            TreeNode* top_tree = s.top();
            s.pop();
            ans.push_back(top_tree->data);
            if(top_tree->right != NULL)
            {
                s.push(top_tree->right);
            }
            if(top_tree->left != NULL)
            {
                s.push(top_tree->left);
            }
        }
        return ans;
	}
};

int main(){
    
    return 0;
}