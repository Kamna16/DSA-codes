#include<bits/stdc++.h>
using namespace std;

// brute Force
class Solution {
    bool ispalindrome(string s, int l,int r)
    {
        if(l>=r) return true;
        if(s[l]==s[r])
        {
            return ispalindrome(s,l+1,r-1);
        }
        return false;
    }
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int n = s.size();
        int max_len = 1;
        int st=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(ispalindrome(s,i,j) && (j-i+1) > max_len)
                {
                    st=i;
                    max_len = j-i+1;
                }
            }
        }
        return s.substr(st,max_len);
    }
};

int main(){
    
    return 0;
}