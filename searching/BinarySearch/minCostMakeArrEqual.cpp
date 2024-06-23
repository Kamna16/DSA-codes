#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calcCost(int mid, vector<int>& nums, vector<int>& cost)
    {
        long long currcost = 0;
        for(int i=0;i<nums.size();i++)
        {
            currcost += (long long)abs(mid-nums[i]) * cost[i];
        }
        return currcost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long totalCost= INT_MIN;
        int l= *min_element(nums.begin(),nums.end());
        int r= *max_element(nums.begin(),nums.end());
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            long long cost1 = calcCost(mid,nums,cost);
            long long cost2 = calcCost(mid+1,nums,cost);
            totalCost = min(cost1,cost2);
            if(cost1<cost2)
            {
                r=mid-1;
            }else l=mid+1;

        }
        return totalCost == INT_MIN ? 0 : totalCost;
    }
};