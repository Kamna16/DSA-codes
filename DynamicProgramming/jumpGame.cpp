#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n= nums.size();
		int max_index =0;
		for(int i=0;i<n;i++)
		{
			if(i > max_index) return false;
			if(i+nums[i] > max_index) max_index= i+nums[i];
		}
		return true;
	}
}; 
class Solution {
public:
	int jump(vector<int>& nums, int index,int n,vector<int>& dp)
	{
		if(index == n-1) return 1;
		if(dp[index] != -1) return dp[index];
		for(int i=1;i<= nums[index];i++)
		{
			if(i+index < n)
			{
				if(jump(nums,i+index,n,dp) == 1) return dp[index] =  1;
			}
		}
		return dp[index] = 0;
	}
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n+1,-1);
		return jump(nums,0,n,dp);
	}
}; 

int main(){
    
    return 0;
}