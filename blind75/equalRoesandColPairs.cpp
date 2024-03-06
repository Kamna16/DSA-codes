#include<bits/stdc++.h>
using namespace std;
// brute force
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n= grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int isEqual=true;
                for(int k=0;k<n;k++)
                {
                    if(grid[i][k] != grid[k][j])
                    {
                        isEqual=false;
                    break;
                    }
                }
                if(isEqual==true) count++;
            }
        }
        return count;
    }
};
// better
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n= grid.size();
        map<vector<int>,int> mp;
        // iterate through row
        for(int i=0;i<n;i++)
        {
            mp[grid[i]]++;
        }
        // iterate through column
        for(int i=0;i<n;i++)
        {
            vector<int> curr;
            for(int j=0;j<n;j++)
            {
                curr.push_back(grid[j][i]);
            }
            count += mp[curr];
        }
        return count;
    }
};

int main(){
    
    return 0;
}