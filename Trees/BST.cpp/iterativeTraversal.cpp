#include <iostream>
#include <stack>

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

class IterativeTreeTraversal {
public:
    // Iterative Inorder Traversal
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;

        std::stack<TreeNode*> stack;
        TreeNode* current = root;

        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            current = stack.top();
            stack.pop();
            std::cout << current->data << " ";
            current = current->right;
        }
    }

    // Iterative Preorder Traversal
    void preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;

        std::stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* current = stack.top();
            stack.pop();
            std::cout << current->data << " ";

            if (current->right != nullptr)
                stack.push(current->right);

            if (current->left != nullptr)
                stack.push(current->left);
        }
    }

    // Iterative Postorder Traversal
    void postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;

        std::stack<TreeNode*> stack1;
        std::stack<TreeNode*> stack2;
        stack1.push(root);

        while (!stack1.empty()) {
            TreeNode* current = stack1.top();
            stack1.pop();
            stack2.push(current);

            if (current->left != nullptr)
                stack1.push(current->left);

            if (current->right != nullptr)
                stack1.push(current->right);
        }

        while (!stack2.empty()) {
            TreeNode* current = stack2.top();
            stack2.pop();
            std::cout << current->data << " ";
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
    IterativeTreeTraversal traversal;
    TreeNode* root = createBinaryTree();

    std::cout << "Inorder Traversal: ";
    traversal.inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    traversal.preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    traversal.postorderTraversal(root);
    std::cout << std::endl;

    // Don't forget to free memory for the binary tree to avoid memory leaks
    // Here, you need to implement a function to delete the tree nodes
    // and then delete the root node. For simplicity, I'm omitting it here.

    return 0;
}
