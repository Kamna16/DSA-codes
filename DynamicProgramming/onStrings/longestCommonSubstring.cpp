#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[1001][1001];
    
    int solve(string& s1, string& s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int longestCommonSubstr(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int maxLength = 0;
        for (int i = 0; i < s1.size(); ++i) {
            for (int j = 0; j < s2.size(); ++j) {
                maxLength = max(maxLength, solve(s1, s2, i, j));
            }
        }
        return maxLength;
    }
};

class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if(n <= 0 || m <= 0) return 0;
       vector<vector<int>> dp(n+1, vector<int>(m+1));
       for(int i=0;i<n+1;i++)
       {
            dp[i][0] = 0;
       }
       for(int i=0;i<m+1;i++)
       {
            dp[0][i] = 0;
       }
       for(int i=1;i<n+1;i++)
       {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
       }
       return dp[n][m];
    }
};