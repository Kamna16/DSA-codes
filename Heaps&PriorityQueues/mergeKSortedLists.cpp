#include<bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode* next;

        SinglyLinkedListNode() {
            this->data = 0;
            this->next = NULL;
        }

        SinglyLinkedListNode(int data) {
            this->data = data;
            this->next = NULL;
        }

        SinglyLinkedListNode(int data, SinglyLinkedListNode* next) {
            this->data = data;
            this->next = next;
        }
};

class Solution {
public:
	SinglyLinkedListNode*  mergeKLists(vector< SinglyLinkedListNode* >& lists) {
		int size = lists.size();
        if(size == 0) return NULL;
        // declaring min heap
        priority_queue<pair<int,SinglyLinkedListNode*>,  vector<pair<int,SinglyLinkedListNode*>>, greater<pair<int,SinglyLinkedListNode*>>> heap;
        // inserting starting elements of ll in heap
        for(int i=0;i<size;i++)
        {
            if(lists[i] != NULL){
                heap.push({lists[i]->data, lists[i]});
            }
        }
        SinglyLinkedListNode* tail = NULL; // anstail
        SinglyLinkedListNode* head = NULL; // anshead
        while(!heap.empty())
        {
            pair<int,SinglyLinkedListNode*> p=heap.top();
            heap.pop();
            SinglyLinkedListNode* x = p.second;
            SinglyLinkedListNode* y = x->next; // to keep track of next element in ll
            x->next = NULL; // y = NULL
            if(tail == NULL)
            {
                head = x;
                tail = x;
            }
            else{
                tail->next = x; // x will be current tail
                tail = tail->next; // update tail
            }
            x = y; // assigning x to next element of linked list
            if(x!= NULL)
            {
                heap.push({x->data,x});
            }
        }
        return head;
	}
};

int main(){
    
    return 0;
}