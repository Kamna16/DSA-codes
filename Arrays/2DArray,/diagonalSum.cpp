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

int main(){
    
    return 0;
}