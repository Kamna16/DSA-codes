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
void insertBST(Node* root,int val)
{
    Node* newnode = new Node(val);
    if(val < root->data)
    {
        root->Left = newnode;
    }
    else{
        root->Right = newnode;
    }
}
void display(Node* root)
{
    if(root == NULL) return;

    cout<<root->data<<" ";
    display(root->Left);
    display(root->Right);
}
int main(){
    struct Node* root = new Node(3);
    // root->Left = new Node(2);
    // root->Right = new Node(3);

    insertBST(root,2);
    insertBST(root,4);
    display(root);
    return 0;
}