#include<bits/stdc++.h>
using namespace std;
class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode* next;

        SinglyLinkedListNode() {
            this->data = 0;
            this->next = NULL;
        }

        SinglyLinkedListNode(int data) {
            this->data = data;
            this->next = NULL;
        }

        SinglyLinkedListNode(int data, SinglyLinkedListNode* next) {
            this->data = data;
            this->next = next;
        }
};

class Solution {
public:
	SinglyLinkedListNode*  addTwoNumbers(SinglyLinkedListNode* & l1, SinglyLinkedListNode* & l2) {
		SinglyLinkedListNode *ansHead = NULL;
		SinglyLinkedListNode *ansTail = NULL;
        int carry=0;
        while(l1 != NULL && l2 != NULL)
        {
            int sum = l1->data +l2->data + carry;
            int value = sum%10;
            carry = sum/10;
            SinglyLinkedListNode * newNode = new SinglyLinkedListNode(value);
            if(ansHead == NULL && ansTail == NULL)
            {
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail->next = newNode;
                ansTail = newNode;
            } 
            l1 = l1->next;   
            l2 = l2->next;   
        }
        while(l1 != NULL)
        {
            int sum = l1->data + carry;
            int value = sum%10;
            carry = sum/10;
            SinglyLinkedListNode * newNode = new SinglyLinkedListNode(value);
            if(ansHead == NULL && ansTail == NULL)
            {
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail->next = newNode;
                ansTail = newNode;
            }  
            l1 = l1->next;   
        }
        while(l2 != NULL)
        {
            int sum = l2->data + carry;
            int value = sum%10;
            carry = sum/10;
            SinglyLinkedListNode * newNode = new SinglyLinkedListNode(value);
            if(ansHead == NULL && ansTail == NULL)
            {
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail->next = newNode;
                ansTail = newNode;
            }  
            l2 = l2->next;   
        }
        if(carry == 1)
        {
            SinglyLinkedListNode * newNode = new SinglyLinkedListNode(carry);
            if(ansHead == NULL && ansTail == NULL)
            {
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail->next = newNode;
                ansTail = newNode;
            }  
        }
        return ansHead;
	}
};

int main(){
    
    return 0;
}