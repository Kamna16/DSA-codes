#include<bits/stdc++.h>
using namespace std;
class dequeue{
    public:
    int size= 10;
    int arr[10];
    int front;
    int rear;
    dequeue()
    {
        front = rear = -1;
    }
    void insert(int elem);
};
void dequeue::insert(int elem)
{
    if(rear == size-1)
    {
        cout<<"queue is full!!"<<endl;
    }
    // arr is empty
    if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        arr[rear] = elem;
    }
    // there is only one element
    else
    {
        rear++;
        arr[rear] = elem;
    }
}
void display()
{
    
}

int main(){
    dequeue d;

    return 0;
}