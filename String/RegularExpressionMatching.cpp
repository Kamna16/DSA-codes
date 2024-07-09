#include<bits/stdc++.h>
using namespace std;

// Hard

class Solution { // ---> TLE
public:
    bool solve(string s, string p)
    {
        if(p.length()==0)
        {
            return s.length()==0;
        }
        bool firstCharMatched = false;
        if(s.length()>0 && (s[0]==p[0] || p[0]=='.'))
            firstCharMatched = true;

        if(p[1] == '*')
        {
            bool take = firstCharMatched && solve(s.substr(1),p);
            bool not_take = solve(s,p.substr(2));
            return take || not_take;
        }
        return firstCharMatched && solve(s.substr(1),p.substr(1));
    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};

// optimal --> using indices + dp
class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string s, string p,int i,int j)
    {
        if(j>=p.length())
        {
            return i>=s.length();
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool firstCharMatched = false;
        if(i<s.length() && (s[i]==p[j] || p[j]=='.'))
            firstCharMatched = true;

        if(p[j+1] == '*')
        {
            bool take = firstCharMatched && solve(s,p,i+1,j);
            bool not_take = solve(s,p,i,j+2);
            return dp[i][j] = take || not_take;
        }
        return dp[i][j] = firstCharMatched && solve(s,p,i+1,j+1);
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0);
    }
};