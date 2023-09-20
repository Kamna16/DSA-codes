#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int value){
        this->val = value;
        this->next =NULL;
    }
};
void insertAtFirst(node* &head, int val, node* &tail)
{
    node* newnode = new node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    newnode -> next = head;
    tail = head;
    head = newnode;
}
void insertAtEnd(node* &head, int val,node* &tail)
{
    node* newnode = new node(val);
    if(tail == NULL)
    {
        insertAtFirst(head,val,tail);
    }
    tail->next = newnode;
    tail = newnode;
}
void insertInMiddle(node* &head, int val,int pos,node* &tail)
{
    if(pos == 0)
    {
        insertAtFirst(head,val,tail);
    }
    int current = 0;
    node* newnode = new node(val);
    node* currentnode = head;
    while(current != pos-1)
    {
        currentnode = currentnode->next;
        current++;
    }
    node* temp = currentnode->next;
    currentnode->next = newnode;
    newnode->next = temp;
}
int TraverseRecursion(node* &head)
{
    if (head == nullptr)
            return 0;
        return 1 + TraverseRecursion(head->next);
}
node* get(int index,node* &head)
{
    node* temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
    
}
void deleteFirst(node* &head,node* &tail)
{
    if(head == NULL)
    {
        cout<<"Nothing to delete"<<endl;
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
}
void deleteLast(node* &head,node* &tail)
{
    if(tail == NULL)
    {
        cout<<"Nothing to delete";
    }
    int current=0;
    node* currnode = head;
    while(currnode->next != tail)
    {
        currnode = currnode-> next;
    }
    node* temp = currnode-> next;
    currnode->next = NULL;
    delete temp;
}
void deletemiddle(node* &head,int index)
{
    if(head == NULL)
    {
        cout<<"Nothing to delete"<<endl;
        return;
    }
    int current=0;
    node* curr = head;
    while(current != index-1)
    {
        curr= curr->next;
        current++;
    }
    node*temp = curr->next;
    curr->next = temp->next;
    delete temp;
}
void display(node* head)
{
    node* newnode;
    newnode =  head;
    while(newnode != NULL)
    {
        cout<<newnode->val<<"->";
        newnode=newnode->next;
    }cout<<"NULL"<<endl;;
}
void printReverse()
{

}
int main(){
    node* head = NULL; 
    node* tail = NULL;

    insertAtFirst(head,7,tail);
    insertAtFirst(head,4,tail);
    cout<<"head is : "<<head->val<<endl;
    cout<<"tail is : "<<tail->val<<endl;
    insertAtEnd(head,10,tail);
    insertAtEnd(head,99,tail);
    insertInMiddle(head,8,2,tail);
    insertInMiddle(head,11,4,tail);
    insertInMiddle(head,55,3,tail);
    deletemiddle(head,2);
    display(head);
    // deleteFirst(head,tail);
    // deleteLast(head,tail);

    return 0;
}