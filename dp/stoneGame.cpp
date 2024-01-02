#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int pick(vector<int>& piles, int i, int j,vector<vector<int>>& dp)
	{
		if(i>j) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		int opt1 = piles[i] - pick(piles,i+1,j,dp);
		int opt2 = piles[j] - pick(piles,i,j-1,dp);
		return dp[i][j] = max(opt1,opt2);
	}
	bool stoneGame(vector<int>& piles) {
		int n = piles.size();
		vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
		return pick(piles,0,n-1,dp);
	}
};

int main(){
    
    return 0;
}