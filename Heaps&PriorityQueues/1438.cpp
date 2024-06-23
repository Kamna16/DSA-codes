#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n =nums.size();
        int i=0, j=0;
        int currmin = INT_MAX;
        priority_queue<pair<int,int>> maxHeap;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap; 
        int maxCount =0;
        while(j<n)
        {
            maxHeap.push({nums[j], j});
            minHeap.push({nums[j], j});
            if((maxHeap.top().first)-(minHeap.top().first) <= limit)
            {
                maxCount = max(maxCount,j-i+1);
            }
            else
            {
                if(minHeap.top().second < maxHeap.top().second)
                {
                    i = minHeap.top().second +1;
                }else i = maxHeap.top().second +1;
                while(maxHeap.top().second < i)
                {
                    maxHeap.pop();
                }
                while(minHeap.top().second < i)
                {
                    minHeap.pop();
                }
            }
            j++;
        }
        return maxCount;
    }
};