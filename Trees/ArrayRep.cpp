#include <iostream>
using namespace std;

class ArrayBinaryTree {
private:
    int* arr;
    int size;

public:
    ArrayBinaryTree(int* values, int n) {
        arr = new int[n];
        size = n;
        for (int i = 0; i < n; i++) {
            arr[i] = values[i];
        }
    }

    int getRoot() {
        return arr[0];
    }

    int getLeftChild(int index) {
        int leftIndex = 2 * index + 1;
        if (leftIndex >= size || arr[leftIndex] == -1) {
            return -1;
        }
        return arr[leftIndex];
    }

    int getRightChild(int index) {
        int rightIndex = 2 * index + 2;
        if (rightIndex >= size || arr[rightIndex] == -1) {
            return -1;
        }
        return arr[rightIndex];
    }
};


int main() {
    // Usage
    int values[] = {10, 5, 20, 3, 8, 15, 25};
    int n = sizeof(values) / sizeof(values[0]);
    ArrayBinaryTree tree(values, n);

    std::cout << "Root: " << tree.getRoot() << std::endl; // Output: Root: 10
    std::cout << "Left child of 5: " << tree.getLeftChild(1) << std::endl; // Output: Left child of 5: 3
    cout << "Right child of 5: " << tree.getRightChild(1) << std::endl; // Output: Right child of 5: 8
    return 0;
}

