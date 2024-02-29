#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int tri(int n,vector<int> &dp)
    {
        if(n ==0 || n==1) return n;
        if(n==2) return 1;
        if(dp[n] != -1) return dp[n];
        int a = tri(n-3,dp);
        int b = tri(n-2,dp);
        int c = tri(n-1,dp);
        return dp[n] = a+b+c;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        
        return tri(n,dp);
    }
};

int main(){
    
    return 0;
}