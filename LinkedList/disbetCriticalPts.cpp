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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        int minima = INT_MAX;
        int i=1;
        int prevCriticalPos=-1;
        int firstCriticalPos=-1;
        while(curr != NULL &&curr->next != NULL)
        {
            if((curr->next->val > curr->val && prev->val > curr->val) || (curr->next->val < curr->val && prev->val < curr->val)) // local maxima and minima
            {
                if(prevCriticalPos == -1){
                    firstCriticalPos=i;
                }
                else{
                    minima = min(i-prevCriticalPos,minima);
                }
                prevCriticalPos = i;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if(prevCriticalPos == -1 || firstCriticalPos == prevCriticalPos) return {-1,-1};
        int maxima = prevCriticalPos-firstCriticalPos;
        return {minima,maxima};
    }
};