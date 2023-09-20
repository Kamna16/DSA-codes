#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;

//         while(curr !=NULL)
//         {
//             ListNode* forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }

//         return prev;
//     }
// };



//      RECURSIVE WAY

class Solution {
public:
    ListNode* helper(ListNode* head) 
    {
        if(head->next == NULL) return head;
        ListNode *newHead =  helper(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        return helper(head);
    }
};

int main(){
    
    return 0;
}