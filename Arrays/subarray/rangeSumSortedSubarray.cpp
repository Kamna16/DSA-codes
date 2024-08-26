#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
class Solution {
public:
    #define mod 1000000007
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum+= nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        long long sum =0;
        for(int i=left-1;i<=right-1;i++)
        {
            sum+= v[i];
        }
        return sum%mod;
    }
};

// using heap
class Solution {
public:
    #define mod 1000000007
    #define p pair<int,int>
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<p,vector<p>, greater<p>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i], i});
        }
        vector<int> ans;
        for(int count =1;count<=right;count++)
        {
            p top = pq.top();
            pq.pop();
            ans.push_back(top.first);
            pq.push({top.first+nums[top.second+1], top.second+1});
        }
        sort(ans.begin(), ans.end());
        long long sum =0;
        for(int i=left-1;i<=right-1;i++)
        {
            sum+= ans[i];
        }
        return sum%mod;
    }
};