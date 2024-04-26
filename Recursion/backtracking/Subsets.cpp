#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subsets/

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans, int start,vector<int> &temp)
    {
        ans.push_back(temp);
        if (start == nums.size()) {
            return;
        }

        for(int i=start;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        backtrack(nums,ans,i+1,temp);
        temp.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums,ans, 0, temp);
        return ans;
    }
};

int main(){
    
    return 0;
}