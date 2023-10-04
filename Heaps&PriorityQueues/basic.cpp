#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] < heap[index]) {
                std::swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChildIdx = 2 * index + 1;
            int rightChildIdx = 2 * index + 2;
            int largestIdx = index;

            if (leftChildIdx < size && heap[leftChildIdx] > heap[largestIdx]) {
                largestIdx = leftChildIdx;
            }

            if (rightChildIdx < size && heap[rightChildIdx] > heap[largestIdx]) {
                largestIdx = rightChildIdx;
            }

            if (largestIdx != index) {
                std::swap(heap[index], heap[largestIdx]);
                index = largestIdx;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty.");
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    int peekMax() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty.");
        }
        return heap[0];
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(8);
    maxHeap.insert(7);

    std::cout << "Max element: " << maxHeap.peekMax() << std::endl; // Output: 30

    std::cout << "Extracting max element: " << maxHeap.extractMax() << std::endl; // Output: 30

    std::cout << "Max element after extraction: " << maxHeap.peekMax() << std::endl; // Output: 20

    return 0;
}
