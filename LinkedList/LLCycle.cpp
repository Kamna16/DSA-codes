#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

// using map
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;
        ListNode *temp = head;
        bool flag = false;
        while(temp != NULL)
        {
            if(mp[temp]<=0)
            {
            mp[temp]++;
            } else return true;
            temp = temp->next;
        }

        return false;
    }
};

// slow fast pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast == slow)
            {
                return true;  // cycle is present
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}