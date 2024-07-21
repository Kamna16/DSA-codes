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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        while(l1 != NULL)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry =0;
        ListNode* newNode = NULL;
        while(!st1.empty() || !st2.empty())
        {
            int a =0, b=0;
            if(!st1.empty())
            {
                a = st1.top();
                st1.pop();
            }
            if(!st2.empty())
            {
                b= st2.top();
                st2.pop();
            }

            int total = a+b+carry;
            carry = total/10;
            ListNode* newN = new ListNode(total%10);
            newN->next = newNode;
            newNode = newN;
        }
        if(carry != 0)
        {
            ListNode* newN = new ListNode(carry);
            newN->next = newNode;
            newNode = newN;
        }
        return newNode;

    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* new1 = reverse(l1);
        ListNode* new2 = reverse(l2);
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        
        while (new1 != NULL || new2 != NULL || carry != 0) {
            int sum = carry;
            if (new1 != NULL) {
                sum += new1->val;
                new1 = new1->next;
            }
            if (new2 != NULL) {
                sum += new2->val;
                new2 = new2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        
        ListNode* result = reverse(dummy->next);
        
        return result;
    }
};
