#include<bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     pair<int,int> DiameterAndHeight(Node* root)
//     {
//         if(root == NULL){
//             pair<int,int> p = {0,0};
//             return p;
//         }
//         pair<int,int> left = DiameterAndHeight(root->left);
//         pair<int,int> right = DiameterAndHeight(root->right);
        
//         int opt1= left.first;
//         int opt2= right.first;
//         int opt3 = left.second+right.second+1;
        
//         pair<int,int> ans;
//         ans.first = max(opt1,max(opt2,opt3));
//         ans.second = max(left.second,right.second)+1;
//         return ans;
//     }
//     int diameter(Node* root) {
//         return DiameterAndHeight(root).first;
//     }
// };


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
int diameter = 0;
    int helper( TreeNode* & root) //O(n^2)
    {
        if(root == NULL) return 0;
        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);

        int currHeight  = max(leftHeight,rightHeight) + 1;

        diameter = max(diameter, leftHeight +  rightHeight);
        return currHeight;
    }
	int diameterOfBinaryTree(TreeNode* & root) {
        helper(root);
		return diameter;
	}
};

int main(){
    
    return 0;
}