#include<bits/stdc++.h>
using namespace std;
bool divisorGame(int n) {
        return n%2 ==0;
}
class Solution {
public:
	bool game(int n, vector<int>& dp)
	{
		if(n==1) return false;
		if(dp[n] != -1) return dp[n];
		for(int i=1;i<n;i++)
		{
			if(n%i ==0)
			{
				if(game(n-i, dp) == false) return dp[n] = true;
			}
		}
		return dp[n] = false;
	}
	bool divisorGame(int n) {
		vector<int> dp(n+1,-1);
		if(game(n,dp) == true) return true;
		return false;
	}
};
int main(){
    
    return 0;
}