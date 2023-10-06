#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = nums.size();
        int i=0;
        // insert k elements in heap
        while(i<k)
        {
            q.push(nums[i]);
            i++;
        }

        // adding next n-k elements in queue , only insertion & simultaneous deletion
        while(i<n)
        {
            if(nums[i] > q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
            i++;
        }
        return q.top();
    }
};

int main(){
    
    return 0;
}