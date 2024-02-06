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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> answer; // store answer level wise
        // initially add root node
        q.push(root);
        while(!q.empty())
        {
            // remove all nodes having similar level at once
            int totalNoOfNodesRemoved = q.size();
            vector<int> currentLevelNodes = {};
            for(int i=0;i< totalNoOfNodesRemoved; i++)
            {
                currentLevelNodes.push_back(q.front()->val);
                if(q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            answer.push_back(currentLevelNodes);
        }
        return answer;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}