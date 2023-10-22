#include<bits/stdc++.h>
using namespace std;

int class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q; // { {r,c} , time}
        int vis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({ {i,j} , 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] =0;
                }
            }
        }
        int finalTime = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        // bfs
        while(!q.empty())
        {
           int r = q.front().first.first;
           int c = q.front().first.second;
           int t = q.front().second;
           finalTime = max(finalTime, t);
           q.pop();
           // visit neighbours
           for(int i=0;i<4;i++)
           {
               int nrow = r + delrow[i];
               int ncol = c + delcol[i];
               if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
               {
                   q.push({ {nrow, ncol}, t+1});
                   vis[nrow][ncol] =2;
               }
           }
        }
        // check whether all oranges got converted to rotten
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        } 

        return finalTime;
    }
};main(){
    
    return 0;
}