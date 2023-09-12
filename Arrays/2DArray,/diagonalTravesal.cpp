#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();
		vector<int> ans; 
		for(int d=0;d<(m+n)-1;d++)
		{
			 if (d % 2 == 0) {
                // Traverse upwards
                for (int i = min(d, n - 1); i >= 0 && d - i < m; i--) {
                    ans.push_back(mat[i][d - i]);
                }
            } else {
                // Traverse downwards
                for (int i = min(d, m - 1); i >= 0 && d - i < n; i--) {
                    ans.push_back(mat[d - i][i]);
                }
            }
		}
		return ans;
	}
};

int main(){
    
    return 0;
}