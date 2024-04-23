#include<bits/stdc++.h>
using namespace std;

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

int main(){
	
	return 0;
}
