#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* Left;
    struct Node* Right;

    Node(int val)
    {
        data = val;
        Left= NULL;
        Right= NULL;
    }
};

int main(){
    struct Node* root = new Node(1);
    root->Left = new Node(2);
    root->Right = new Node(3);
    return 0;
}