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
    ListNode* swapPairs(ListNode* head) {
        // if there are 0 or 1 element
        if(head == NULL || head->next == NULL) return head;
        
		ListNode *nextNode = head->next;
		ListNode *forwardNode = head->next->next;
        // if there are only 2 elements;
        nextNode->next = head;
        head->next = swapPairs(forwardNode);
        
        return nextNode;
    }
};

int main(){
    
    return 0;
}