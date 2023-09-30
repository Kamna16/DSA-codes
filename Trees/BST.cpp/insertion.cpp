#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    // Method to insert a node into the BST using an iterative approach
    void insert(int data) {
        TreeNode* new_node = new TreeNode(data);
        if (root == nullptr) {
            root = new_node;
            return;
        }

        TreeNode* current = root;
        while (true) {
            if (data < current->data) {
                if (current->left == nullptr) {
                    current->left = new_node;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new_node;
                    return;
                }
                current = current->right;
            }
        }
    }

    // Helper method to create a sample BST
    static BinarySearchTree* createBinarySearchTree() {
        BinarySearchTree* bst = new BinarySearchTree();
        bst->insert(5);
        bst->insert(3);
        bst->insert(7);
        bst->insert(2);
        bst->insert(4);
        bst->insert(6);
        bst->insert(8);
        return bst;
    }
};

// Main function to run the example
int main() {
    BinarySearchTree* bst = BinarySearchTree::createBinarySearchTree();
    cout << "Sample Binary Search Tree has been created!";
    return 0;
}
