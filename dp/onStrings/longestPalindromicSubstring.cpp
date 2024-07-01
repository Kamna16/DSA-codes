#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j])
        {
            return dp[i][j] = 2 + solve(i+1,j-1,s,dp);
        }
        int ans1 = solve(i+1,j,s,dp);
        int ans2 = solve(i,j-1,s,dp);
        return dp[i][j] = max(ans1,ans2);    
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,s.size()-1,s,dp);
    }
};

class Solution {
public:
    vector<vector<int>> isPalindrome;
    bool solve(int i,int j,string s)
    {
        if(i>= j) return true;
        if(isPalindrome[i][j] != -1) return isPalindrome[i][j];
        if(s[i] == s[j])
        {
            return isPalindrome[i][j] = solve(i+1,j-1,s);
        }
        return isPalindrome[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
       isPalindrome.resize(n,vector<int>(n,-1));
        int startPt=0;
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(solve(i,j,s) && (j-i+1 > maxlen))
                {
                    maxlen = j-i+1;
                    startPt = i;
                }
            }
        }
        return s.substr(startPt,maxlen);
    }
};

// Bottom up  --> revise
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int L=2;L<=n;L++)
        {
            for(int i=0;i<n-L+1;i++)
            {
                int j= i+L-1;
                if(s[i]==s[j]){
                    dp[i][j] = 2+dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};