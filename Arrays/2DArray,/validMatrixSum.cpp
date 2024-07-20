#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    void solve(vector<int>& rowSum, vector<int>& colSum,vector<vector<int>> &ans, int i, int j)
    {
        if(i>= m || j>= n) return;

        ans[i][j] = min(rowSum[i],colSum[j]);
        colSum[j] -= ans[i][j];
        rowSum[i] -= ans[i][j];
        if (rowSum[i] == 0 && colSum[j] == 0) {
            solve(rowSum, colSum, ans, i + 1, j + 1);
        } else if (rowSum[i] == 0) {
            solve(rowSum, colSum, ans, i + 1, j);
        } else if (colSum[j] == 0) {
            solve(rowSum, colSum, ans, i, j + 1);
        } else {
            solve(rowSum, colSum, ans, i, j + 1);
        }
        
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
      m = rowSum.size();
      n = colSum.size();
      vector<vector<int>> result(m,vector<int>(n));
      solve(rowSum,colSum,result,0,0);
      return result;  
    }
}; 