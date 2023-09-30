#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Inorder Traversal
static void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal
static void preorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal
static void postorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    // Usage
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(25);

    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    // Don't forget to free memory for the binary tree to avoid memory leaks
    // Here, you need to implement a function to delete the tree nodes
    // and then delete the root node. For simplicity, I'm omitting it here.

    return 0;
}
