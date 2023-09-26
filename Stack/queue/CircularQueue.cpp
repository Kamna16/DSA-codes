#include<bits/stdc++.h>
using namespace std;
class MyCircularQueue {
public:
    int front;
    int rear;
    vector<int> arr;
    int size;
    int totalElementsPresent;
	MyCircularQueue(int k) {
        arr.resize(size);
        size=k;
        totalElementsPresent=0;
        front = -1;
        rear = -1;
	}

	bool enQueue(int value) {
        if(totalElementsPresent == size) return false;
		if(front ==-1 && rear == -1)
        {
            front =0;
            rear=0;
        }
        else{
            rear = (rear+1) % size;
        }
        totalElementsPresent++;
        arr[rear] = value;
        return true;
	}

	bool deQueue() {
		if(totalElementsPresent ==0) return false;
        front = (front +1) %size;
        totalElementsPresent--;
        return true;
	}

	int Front() {
        if(totalElementsPresent ==0) return -1;
		return arr[front];
	}

	int Rear() {
		if(totalElementsPresent ==0) return -1;
		return arr[rear];
	}

	bool isEmpty() {
		if(totalElementsPresent ==0) return true;
        else return false;
	}

	bool isFull() {
		if(totalElementsPresent == size) return true;
        else return false;
	}
};

int main(){
    
    return 0;
}