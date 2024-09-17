#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/top-k-frequent-elements/submissions/1068667552/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto x : mp)
        {
            pq.push({x.second,x.first});
            while(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty())
        {
            int num = pq.top().second;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};

// using bucket sort like algo
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto p : mp)
        {
            freq[p.second].push_back(p.first);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--)
        {
            while(freq[i].size() > 0 && k >0)
            {
                ans.push_back(freq[i].back());
                freq[i].pop_back();
                k--;
            }
            if(k <=0) break;
        }
        return ans;
    }
};