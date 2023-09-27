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

int main(){
    
    return 0;
}