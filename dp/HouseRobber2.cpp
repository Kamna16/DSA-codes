#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// states - (index, firstChosen)
	// transition time = 1
	// TC = Space complexity + transition time 
	int dp[101][2];
    int recur(int index, vector<int> &nums, int firstChosen)
    {
        if(index >= nums.size())
        {
            return 0;
        }
        
        if(dp[index][firstChosen] != -1)
        {
            return dp[index][firstChosen];
        }
        
        int option1 = 0;
        int option2 = 0;
        
        // choosing an element 
        if(index == (nums.size()-1)) // last index 
        {
            if(firstChosen == 0) // first element should not be choosen 
            {
                option1 = nums[index] + recur(index + 2, nums, firstChosen | (index == 0));
            }
        }
        else // every other index 
        {
            option1 = nums[index] + recur(index + 2, nums, firstChosen | (index == 0));
        }
        
        // don't choose ith element and go forward 
        option2 = recur(index + 1, nums, firstChosen);
        
        int answer = max(option1, option2);
        dp[index][firstChosen] = answer;
        return answer;
    }

	int rob(vector<int>& nums) {
		memset(dp, -1, sizeof(dp)); 
		return recur(0, nums, 0);
		// for(int i=0;i<101;i++)
		// {
		// 	for(int j=0;j<2;j++)
		// 	{
		// 		dp[i][j] =-1;
		// 	}
		// }
	}
};
int main(){
    
    return 0;
}