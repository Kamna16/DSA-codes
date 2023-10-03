#include<bits/stdc++.h>
using namespace std;
// memoization
class Solution {
public:
    int waysToReachN(int n, vector<int> &dp)
    {
        if(n==0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = waysToReachN(n-1,dp)+waysToReachN(n-2,dp);
    }
    int climbStairs(int n) {
      vector<int> dp(n+1,-1);
      return waysToReachN(n,dp);  
    }
};
// tabulation
class Solution {
public:
    int climbStairs(int n) {
      if(n<=2)
         return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
    }
};
int main(){
    
    return 0;
}