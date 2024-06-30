#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-k-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        int n= lists.size();
        for (ListNode* list : lists) {
            ListNode* current = list;
            while (current) {
                values.push_back(current->val);
                current = current->next;
            }
        }
        sort(values.begin(), values.end());
        ListNode* dummyHead  = new ListNode();
        ListNode* temp = dummyHead ;
        for(int i : values)
        {
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        return dummyHead->next;
    }
};

// using prority queue
class Solution {
public:
    struct ComparePairs {
        bool operator()(const pair<int, ListNode*>& a, const pair<int, ListNode*>& b) const {
            return a.first > b.first; // Compare based on the integer values
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, ComparePairs> pq;
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(!pq.empty())
        {
            ListNode* value = pq.top().second;
            temp->next = value;
            pq.pop();
            if(value->next)
            {
                pq.push({value->next->val,value->next});
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};

// approach 3
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* result;
        if(list1->val <= list2->val)
        {
            result = list1;
            result->next = mergeTwoLists(list1->next,list2);
        }else{
            result = list2;
            result->next = mergeTwoLists(list1,list2->next);
        }
        return result;
    }
    ListNode* partitionMerge(int s, int e,vector<ListNode*>& lists){
        if(s>e) return NULL;
        if(s == e) return lists[s];
        int mid = s+(e-s)/2;
        ListNode* l1 = partitionMerge(s,mid,lists);
        ListNode* l2 = partitionMerge(mid+1,e,lists);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int  k = lists.size();
        if(k ==0) return NULL;
        return partitionMerge(0,k-1,lists);
    }
};