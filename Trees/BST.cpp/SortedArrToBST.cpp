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
    TreeNode* recur(vector<int>& nums, int start, int end)
    {
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = recur(nums, start, mid-1);
        root->right = recur(nums, mid+1, end);

        return root;
    }
	TreeNode*  sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();
        return recur(nums, 0, n-1);
	}
};

int main(){
    
    return 0;
}