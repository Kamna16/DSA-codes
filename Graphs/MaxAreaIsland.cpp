#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int Area(int i, int j,vector<vector<int>>& grid,int n,int m)
	{
		if(i<0 || i>=n || j<0 || j>=m || grid[i][j] ==-1 || grid[i][j] ==0) return 0;
		grid[i][j] = -1;
		int ansUp =  Area(i-1,j,grid,n,m);
		int ansDown = Area(i+1,j,grid,n,m);
		int ansleft = Area(i,j-1,grid,n,m);
		int ansRight = Area(i,j+1,grid,n,m);

		return ansUp + ansDown + ansleft + ansRight + 1;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int maxArea = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(grid[i][j] == 1)
				{
					int area = Area(i,j,grid,n,m);
					maxArea = max(area,maxArea);
				}
			}
		}
		return maxArea;
	}
};

int main(){
    
    return 0;
}