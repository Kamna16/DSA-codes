#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    LinkedListStack stack;

    // Push elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    // Pop elements from the stack
    std::cout << stack.pop() << std::endl; // Output: 5
    std::cout << stack.pop() << std::endl; // Output: 4

    // Check if the stack is empty
    std::cout << std::boolalpha << stack.isEmpty() << std::endl; // Output: false

    // Push more elements
    stack.push(6);
    stack.push(7);

    // Pop elements until the stack is empty
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << std::endl;
    }

    return 0;
}
