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
    int pairSum(ListNode* head) {
        vector<int> list;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            list.push_back(temp->val);
            temp = temp->next;
        }
        int i=0;
        int j= list.size()-1;
        int maxi = INT_MIN;
        while(i<j)
        {
            int sum = list[i]+list[j];
            maxi = max(maxi,sum);
            i++;
            j--;
        }
        return maxi;
    }
};

int main(){
    
    return 0;
}