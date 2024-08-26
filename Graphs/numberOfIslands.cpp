#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> visited;
    void bfs(int row, int col,vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traverse in the neighbours(8 directions) and mark them if its a land
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    if((delrow == -1 && delcol == 1) || (delrow == -1 && delcol == -1 ) || (delrow == 1 && delcol == -1) || (delrow ==1 && delcol ==1)) continue;
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow >=0 && nrow <n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !visited[nrow][ncol])
                    {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n, vector<int>(m,0));

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    bfs(i,j,grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int n,m;
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || visited[i][j]) return;

        visited[i][j] = true;

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j]&& grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};