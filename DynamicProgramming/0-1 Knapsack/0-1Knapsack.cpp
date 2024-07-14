#include<bits/stdc++.h>
using namespace std;

//recursive
class Solution
{
    public:
    int recur(int i, int W, int wt[], int val[], int n)
    {
        if(n==0 || W==0) return 0; // Base case: no more items or knapsack capacity exhausted
        
        if(wt[i] > W) return recur(i+1, W, wt, val, n); // If the current item's weight exceeds the capacity, skip it
        
        // Include the current item or skip it, and take the maximum of both
        int left = val[i] + recur(i+1, W - wt[i], wt, val, n-1); // Include the current item
        int right = recur(i+1, W, wt, val, n-1); // Skip the current item
        
        return max(left, right);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {
        return recur(0, W, wt, val, n);
    }
};
// memoized
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int recur(int i, int W, int wt[], int val[], int n, vector<vector<int>>& dp)
    {
        if (i >= n || W <= 0)
            return 0;

        if (dp[i][W] != -1)
            return dp[i][W];

        if (wt[i] > W)
            return dp[i][W] = recur(i + 1, W, wt, val, n, dp);

        int left = val[i] + recur(i + 1, W - wt[i], wt, val, n, dp);
        int right = recur(i + 1, W, wt, val, n, dp);

        return dp[i][W] = max(left, right);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return recur(0, W, wt, val, n, dp);
    }
};



int main(){
    
    return 0;
}