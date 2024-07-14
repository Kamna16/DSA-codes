#include<bits/stdc++.h>
using namespace std;

//memoization
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(row == grid.size()-1 && col == grid[0].size()-1) return grid[row][col];
        
        if(dp[row][col]) return dp[row][col];

        if(col == grid[0].size()-1)
        {
            return dp[row][col] = grid[row][col] + solve(row+1,col,grid,dp);
        }
        else if(row == grid.size()-1)
        {
            return dp[row][col] = grid[row][col] + solve(row,col+1,grid,dp);
        }
        else return dp[row][col] = grid[row][col] + min(solve(row+1,col,grid,dp), solve(row,col+1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        return solve(0,0,grid,dp);
    }
};

// bottom up
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        dp[0][0] = grid[0][0];

        // fill first row
        for(int i=1;i<m;i++)
        {
            dp[0][i] = grid[0][i]+ dp[0][i-1];
        }
        // fill first col
        for(int i=1;i<n;i++)
        {
            dp[i][0] = grid[i][0]+ dp[i-1][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};

int main(){
    
    return 0;
}