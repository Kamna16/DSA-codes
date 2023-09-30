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
    map<int,int> mp;
    int index; // for tracking index of root node
    TreeNode* recur(vector<int>& preorder, int start, int end)
    {
        if(start > end) return NULL;
        TreeNode* rootNode = new TreeNode(preorder[index]);
        index++;
        if(start == end) return rootNode;
        // find where this node is present in inorder
        int whereInorderPresent = mp[rootNode->data]; // root ka index
        rootNode-> left = recur(preorder, start, whereInorderPresent-1);
        rootNode-> right = recur(preorder, whereInorderPresent+1, end);

        return rootNode;
    }
	TreeNode*  buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();
        index = 0;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }

        return recur(preorder, 0, n-1);
	}
};

int main(){
    
    return 0;
}