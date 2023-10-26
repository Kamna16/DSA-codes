#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
	{
		if(i>= s1.length() || j >= s2.length()) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		int ans = 0;
		if(s1[i] == s2[j])
		{
			ans = 1+ helper(i+1,j+1,s1,s2,dp);
		}
		else{
			int opt1 = helper(i+1,j,s1,s2,dp);
			int opt2 = helper(i,j+1,s1,s2,dp);

			ans = max(opt1,opt2);
		}
		return dp[i][j] = ans;
	}
	int longestCommonSubsequence(string text1, string text2) {
		int l1 = text1.size();
		int l2 = text2.size();
		vector<vector<int>> dp(l1,vector<int> (l2,-1));
		return helper(0,0,text1,text2,dp);
	}


};

int main(){
    
    return 0;
}