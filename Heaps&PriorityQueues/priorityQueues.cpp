#include <iostream>

class MinHeap {
private:
    int* heap;
    int size;
    int capacity;

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return 2 * index + 1;
    }

    int getRightChildIndex(int index) {
        return 2 * index + 2;
    }

    bool hasParent(int index) {
        return getParentIndex(index) >= 0;
    }

    bool hasLeftChild(int index) {
        return getLeftChildIndex(index) < size;
    }

    bool hasRightChild(int index) {
        return getRightChildIndex(index) < size;
    }

    void swap(int index1, int index2) {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    void heapifyUp() {
        int index = size - 1;
        while (hasParent(index) && heap[getParentIndex(index)] > heap[index]) {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

    void heapifyDown() {
        int index = 0;
        while (hasLeftChild(index)) {
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && heap[getRightChildIndex(index)] < heap[getLeftChildIndex(index)]) {
                smallerChildIndex = getRightChildIndex(index);
            }

            if (heap[index] < heap[smallerChildIndex]) {
                break;
            } else {
                swap(index, smallerChildIndex);
            }

            index = smallerChildIndex;
        }
    }

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->heap = new int[capacity];
    }

    void insert(int value) {
        if (size == capacity) {
            throw std::runtime_error("Priority Queue is full.");
        }
        heap[size] = value;
        size++;
        heapifyUp();
    }

    int peek() {
        if (size == 0) {
            throw std::runtime_error("Priority Queue is empty.");
        }
        return heap[0];
    }

    int poll() {
        if (size == 0) {
            throw std::runtime_error("Priority Queue is empty.");
        }
        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown();
        return min;
    }

    int getSize() {
        return size;
    }
};

int main() {
    MinHeap minHeap(10);
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(8);

    std::cout << "Peek (Min): " << minHeap.peek() << std::endl; // Output: 5

    while (minHeap.getSize() > 0) {
        std::cout << minHeap.poll() << " "; // Output: 5 8 10 20
    }

    return 0;
}
