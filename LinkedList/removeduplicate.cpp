#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;
//         ListNode* temp = head;
//         while(temp->next != NULL)
//         {
//             if(temp->next->val == temp->val){
//                 ListNode* duplicateNode = temp->next;
//                 temp->next = duplicateNode->next;
//                 delete duplicateNode;
//             }
//             else{
//                 temp= temp->next;
//             }
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = new ListNode(INT_MIN);
        prev->next = curr;
        while(curr)
        {
            if(curr->val != prev->val)
            {
                prev = curr;
                curr = curr->next;
            }else{
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main(){
    
    return 0;
}