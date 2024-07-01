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
    int countSubstrings(string s) {
        int n = s.size();
       isPalindrome.resize(n,vector<int>(n,-1));
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(solve(i,j,s))
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Bottom up
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        int count = 0;
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j= i+L-1;
                if(i==j) t[i][j]=true;
                else if(i+1==j)
                {
                    if(s[i]==s[j]) t[i][j]=true;;
                }
                else{
                    t[i][j]= s[i]==s[j] && t[i+1][j-1];
                }
                if(t[i][j]) count++;
            }
        }
        return count;
    }
};