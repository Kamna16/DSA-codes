#include <iostream>
#include <queue>

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

class LevelOrderTraversal {
public:
    // Level Order Traversal (BFS)
    void levelOrderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            std::cout << current->data << " ";

            if (current->left != nullptr)
                queue.push(current->left);

            if (current->right != nullptr)
                queue.push(current->right);
        }
    }
};

// Helper method to create the binary tree
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(25);
    return root;
}

int main() {
    LevelOrderTraversal traversal;
    TreeNode* root = createBinaryTree();

    std::cout << "Level Order Traversal (BFS): ";
    traversal.levelOrderTraversal(root);
    std::cout << std::endl;

    // Don't forget to free memory for the binary tree to avoid memory leaks
    // Here, you need to implement a function to delete the tree nodes
    // and then delete the root node. For simplicity, I'm omitting it here.

    return 0;
}
