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
    vector<int> arr;
    Solution(ListNode* head) {
        ListNode* curr = head;
        while(curr != NULL)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
    }
    
    int getRandom() {
        int randomIdx = rand()%arr.size();
        return arr[randomIdx];
    }
};

// reservoir sampling