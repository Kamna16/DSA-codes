#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int helper(int house, vector<int> &nums, vector<int> &dp)
	{
		if(house>= nums.size()) return 0;
		if(dp[house] != -1) return dp[house];
		int opt1 =nums[house] +  helper(house+2,nums,dp);
		int opt2 = 0 +  helper(house+1,nums,dp);

		return dp[house] = max(opt1,opt2);
	}
	int rob(vector<int>& nums) {
		vector<int> dp(nums.size()+1, -1);
		return helper(0,nums, dp);
	}
};
int main(){
    
    return 0;
}