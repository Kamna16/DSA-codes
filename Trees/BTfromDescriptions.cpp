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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) { // return root
        unordered_map<int, TreeNode*> store;
        unordered_set<int> children;
        
        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            if (store.find(parent) == store.end()) {
                store[parent] = new TreeNode(parent);
            }

            if (store.find(child) == store.end()) {
                store[child] = new TreeNode(child);
            }

            if (isLeft) {
                store[parent]->left = store[child];
            } else {
                store[parent]->right = store[child];
            }

            children.insert(child);
        }

        for (auto& desc : descriptions) {
            if (children.find(desc[0]) == children.end()) {
                return store[desc[0]];
            }
        }

        return NULL;
    }
};