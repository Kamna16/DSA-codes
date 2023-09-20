#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;
        while(fast != NULL && fast->next != NULL && isCycle != true)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                isCycle = true; //cycle is present
            }
        }
        if(!isCycle) return NULL;

        // change fast tohead of LL
        fast = head;
        while(fast !=slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){
    
    return 0;
}