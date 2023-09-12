#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next; 
    node* prev;
    node(int value){
        this->val = value;
        this->next =NULL;
        this->prev =NULL;
    }
};
void insertAtFirst(node* &head, int val)
{
    node* newnode = new node(val);
    if(head == NULL)
    {
        head = newnode;
    }
    newnode -> next = head;
    head->prev = newnode;
    // tail = head;
    head = newnode;
}
void display(node* head)
{
    node* newnode=  head;
    while(newnode != NULL)
    {
        cout<<newnode->val<<"->";
        newnode=newnode->next;
    }cout<<"NULL"<<endl;;
}
int main(){
    node* head = NULL; 

    insertAtFirst(head,7);
    insertAtFirst(head,4);

    return 0;
}