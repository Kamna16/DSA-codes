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
    // Method to delete a node from the BST
    void deleteNode(int data) {
        root = deleteRec(root, data);
    }

    // Recursive method to delete a node from the BST
    TreeNode* deleteRec(TreeNode* root, int data) {
        if (root == nullptr) {
            return root;
        }

        // Recursively search for the node to be deleted
        if (data < root->data) {
            root->left = deleteRec(root->left, data);
        } else if (data > root->data) {
            root->right = deleteRec(root->right, data);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the in-order successor (minimum node in the right subtree)
            root->data = minValue(root->right);

            // Delete the in-order successor
            root->right = deleteRec(root->right, root->data);
        }

        return root;
    }

    // Helper method to find the minimum value in a tree
    int minValue(TreeNode* root) {
        int minValue = root->data;
        while (root->left != nullptr) {
            minValue = root->left->data;
            root = root->left;
        }
        return minValue;
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
    bst->deleteNode(7);
    cout << "Sample Binary Search Tree with node 7 deleted:";
    return 0;
}
