#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target,vector<int> & curr, int idx)
    {
        if(idx == nums.size()) return;
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        if(nums[idx] <= target)
        {
            curr.push_back(nums[idx]);
            solve(nums,target-nums[idx],curr,idx);
            curr.pop_back();
            solve(nums,target,curr,idx+1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,curr,0);
        return ans;
    }
};

class Solution {
public:
    
    void recur(vector<int>& candidates,int ind, int target, vector<int> &list,vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(list);
            return;
        }

        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

                //pick
            list.push_back(candidates[i]);

            recur(candidates,i,target-candidates[i],list,ans);
            //not pick
            list.pop_back();
        
        }
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> list;
        vector<vector<int>> ans;
        recur(candidates,0,target,list,ans);
        return ans;
    }
};
