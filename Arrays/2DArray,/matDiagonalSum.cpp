#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n = mat.size();
        int m = mat[0].size();
        for(int r=0;r<n;r++)
        {
            int Pdiagonal = mat[r][r];
            int c = m-1-r;
            int Sdiagonal = mat[r][c];
            sum+= Pdiagonal; 
            if(r != c)
                sum+= Sdiagonal; 
        }
        return sum;
    }
};

// using stl 
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row=0;
        auto lambda = [&](int sum, vector<int> v)
        {
            sum += v[row];
            if(row != v.size()-row-1)
            {
                sum += v[v.size()-row-1];
            }
            row ++;
            return sum;
        };
        int result = accumulate(mat.begin(),mat.end(),0,lambda);// calculate sum of given array
        return result;
    }
};