#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row;
        vector<int> col;
        for(int i=0;i<m;i++)// row
        {
            int minrow = INT_MAX;
            for(int j=0;j<n;j++)// col
            {
                minrow = min(minrow,matrix[i][j]);
            }
            row.push_back(minrow);
        }
        for(int i=0;i<n;i++)// col
        {
            int maxcol = INT_MIN;
            for(int j=0;j<m;j++)// row
            {
                maxcol = max(maxcol,matrix[j][i]);
            }
            col.push_back(maxcol);
        }
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == row[i] && matrix[i][j] == col[j])
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};


// there will always be 1 lucky number
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rowMax = INT_MIN;
        int colMin = INT_MAX;
        for(int i=0;i<m;i++)// row
        {
            int minrow = INT_MAX;
            for(int j=0;j<n;j++)// col
            {
                minrow = min(minrow,matrix[i][j]);
            }
            rowMax = max(rowMax,minrow);
        }
        for(int i=0;i<n;i++)// col
        {
            int maxcol = INT_MIN;
            for(int j=0;j<m;j++)// row
            {
                maxcol = max(maxcol,matrix[j][i]);
            }
            colMin = min(colMin,maxcol);
        }
        vector<int> ans;
        if(rowMax == colMin )
        {
            ans.push_back(rowMax);
        }
        return ans;
    }
};