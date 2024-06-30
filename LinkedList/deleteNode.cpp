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
    void deleteNode(ListNode* node) {
        swap(node->val,node->next ->val);
        node -> next = node -> next ->next;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while(node->next != NULL)
        {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
};