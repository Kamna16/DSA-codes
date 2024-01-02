#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int deleteGreatestValue(vector<vector<int>>& grid) {
		int result = 0;

        while (!grid.empty() && !grid[0].empty()) {
            int rowMax = 0;

            for (int i = 0; i < grid.size(); ++i) {
                // Find the maximum element in the current row
                auto maxIt = max_element(grid[i].begin(), grid[i].end());

                // Add the maximum value to the result
                rowMax = max(rowMax, *maxIt);

                // Erase the maximum element from the row
                grid[i].erase(maxIt);

                // Remove any empty rows
                if (grid[i].empty()) {
                    grid.erase(grid.begin() + i);
                    --i;  // Adjust the index after erasing a row
                }
            }

            // Add the maximum of deleted elements to the result
            result += rowMax;
        }

        return result;
	}
};
int main(){
    
    return 0;
}