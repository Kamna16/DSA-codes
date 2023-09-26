#include <iostream>
using namespace std;

// C++
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};


int main() {
    // C++
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(25);

    // Write C++ code here
    std::cout << "Root Node : " << root->data;

    return 0;
}
