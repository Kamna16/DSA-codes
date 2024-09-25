#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int>& candidates, int target,int idx,vector<int> &temp)
    {
        if(target <0) return;
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,target, 0,temp);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target,vector<int> & curr, int idx)
    {
        if(target == 0)
        {
            if(find(ans.begin(), ans.end(), curr) != ans.end()) return;
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<nums.size();i++)
        {
            if(i > idx && nums[i] == nums[i-1]) continue;
            if(nums[i]>target) break;
            curr.push_back(nums[i]);
            solve(nums,target-nums[i],curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,curr,0);
        return ans;
    }
};