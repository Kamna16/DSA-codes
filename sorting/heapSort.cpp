#include <iostream>
#include <vector>

// places a node to its correct place
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Initialize the largest element as the root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        // Swap the root and the largest
        std::swap(arr[i], arr[largest]);

        // Heapify the subtree
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root (maximum) to the end
        std::swap(arr[0], arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
