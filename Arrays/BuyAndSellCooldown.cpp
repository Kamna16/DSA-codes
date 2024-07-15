#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices,int day, int n , bool buy,vector<vector<int>>& dp)
    {
        if(day >= n) return 0;
        if (dp[day][buy] != -1) return dp[day][buy];
        int profit=0;
        if(buy)
        {
            int take = solve(prices, day+1,n,false,dp) - prices[day];
            int not_take = solve(prices, day+1,n,true,dp); // buying
            profit = max(take, not_take); 
        }else{
            int sell = prices[day] + solve(prices, day+2,n,true,dp);
            int not_sell = solve(prices, day+1,n,false,dp);

            profit = max(sell, not_sell);
        }
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        bool buy = true;
        return solve(prices,0,n,buy,dp);
    }
};