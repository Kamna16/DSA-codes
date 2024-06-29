#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans,vector<int> &temp)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            backtrack(nums,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums,ans,temp);
        return ans;
    }
};