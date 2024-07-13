#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// using map
class Solution {
public:
    unordered_map<int,int> mp;
    void inorder(TreeNode* root)
    {
        if(!root) return;

        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int maxFreq=0;
        vector<int> ans;
        for(auto i : mp)
        {
            if(i.second == maxFreq)
            {
                ans.push_back(i.first);
            }
            else if(i.second > maxFreq)
            {
                maxFreq = i.second;
                ans.clear();
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> ans;
    int currNum = 0, currFreq=0,maxFreq=INT_MIN;
    void inorder(TreeNode* root)
    {
        if(!root) return;

        inorder(root->left);
        if(root->val == currNum)
        {
            currFreq++;
        }else{
            currNum = root->val;
            currFreq =1;
        }
        if(currFreq > maxFreq)
        {
            ans.clear();
            maxFreq=currFreq;
        }
        if(currFreq == maxFreq) ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};