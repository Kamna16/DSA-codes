// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

#include<vector>


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int n = nums.size();
		int winningTeam = nums[0];
		int winningScore = 1;
		for(int i=1; i<n ;i++)
		{
			if(winningScore == 0)
			{
				winningTeam= nums[i];
				winningScore = 1;
				continue;
			}
			if(nums[i] == winningTeam) winningScore++;
			else winningScore--;
		}
		return winningTeam;
	}
};