#include<bits/stdc++.h>
using namespace std;
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

int main(){
    
    return 0;
}