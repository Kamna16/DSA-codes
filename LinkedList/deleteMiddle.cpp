#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* curr = head;
        int n=0;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        int count = n/2;
        curr = head;
        while(curr != NULL)
        {
            count--;
            if(count ==0)
            {
                ListNode* middle = curr->next;
                curr->next = curr->next->next;
                delete middle;
                break;
            }
            curr=curr->next;
        }
        
        return head;

    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = head;
        while(curr->next != slow)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};