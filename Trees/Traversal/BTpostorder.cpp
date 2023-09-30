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
        helper(root->left,ans);
        helper(root->right,ans);
        ans.push_back(root->data);
    }
	vector<int> postorderTraversal(TreeNode* & root) {
		vector<int> ans;
        helper(root,ans);
        return ans;
	}
};

// iterative 
vector<int> postorderTraversal(TreeNode* & root) {
		stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);

        while(!s.empty())
        {
            TreeNode* top_tree = s.top();
            if(top_tree->left != NULL)
            {
                TreeNode* leftPart = top_tree->left;
                top_tree->left = NULL; 
                s.push(leftPart);
            }
            else if(top_tree->right != NULL)
            {
                TreeNode* rightPart = top_tree->right;
                top_tree->right = NULL; 
                s.push(rightPart);
            }
            else{
                ans.push_back(top_tree->data);
                s.pop();
            }
        }
        return ans;
}

int main(){
    
    return 0;
}