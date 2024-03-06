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
         if (head == nullptr || head->next == nullptr) {
            return nullptr; // Edge case: empty list or single node
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // To keep track of the node before slow

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now 'slow' points to the middle node
        if (prev != nullptr) {
            prev->next = slow->next; // Skip the middle node
        } else {
            // If 'prev' is nullptr, 'slow' is the head node
            head = head->next;
        }

        delete slow; // Free the memory of the middle node

        return head;
    }
};

int main(){
    
    return 0;
}