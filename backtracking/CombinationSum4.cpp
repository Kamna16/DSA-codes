#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int target,int ind)
    {
        if(target ==0) return 1;
        if(ind >= nums.size() || target <0) return 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        int take_ind = solve(nums,target-nums[ind],0);
        int reject_ind = solve(nums,target,ind+1);
        return dp[ind][target] = take_ind + reject_ind;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));
        return solve(nums,target,0);
    }
};

int main(){
    
    return 0;
}