#include<bits/stdc++.h>
using namespace std;

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