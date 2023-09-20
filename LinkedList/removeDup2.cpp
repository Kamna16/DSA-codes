#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;

        ListNode *answerHead = NULL;
        ListNode *answerTail = NULL;
        while(temp!= NULL)
        {
            // two pointer
            ListNode *i=temp;
            ListNode *j=temp;
            int freq =0;
            while(j != NULL && i->val == j->val) 
            {
                freq++;
                j=j->next;
            }

            if(freq == 1) //unique element and is not duplicate
            {
                //first element 
                if(answerHead == NULL &&answerTail == NULL)
                {
                    answerHead = temp;
                    answerTail = temp;
                }
                else{
                    answerTail->next = temp;
                    answerTail = temp; // update the tail
                }
            }
            temp = j;
        }
        if(answerTail != NULL)
            {
                answerTail->next = NULL;
            }
            
            return answerHead;
    }
};

int main(){
    
    return 0;
}