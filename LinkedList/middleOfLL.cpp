#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
        // temp -> next = temp -> next-> next;
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
    if(head->next->next == NULL) return head->next;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast-> next;
        }
        slow = slow->next;
    }
    return slow;
    }
};
