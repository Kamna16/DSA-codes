#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
		int sum1 = 0, sum2 = 0;
        int n = aliceSizes.size();
        for (int i = 0; i < n; i++) {
            sum1 += aliceSizes[i];
        }
        int m = bobSizes.size();
        for (int i = 0; i < m; i++) {
            sum2 += bobSizes[i];
        }
        sort(aliceSizes.begin(), aliceSizes.end());
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int x = bobSizes[i];
            int y = (sum1 - sum2 + 2 * x) / 2;
            int l = 0;
            int r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (aliceSizes[mid] == y) {
                    ans.push_back(aliceSizes[mid]);
                    ans.push_back(x);
                    return ans;  // Return early as we have found a valid pair
                } else if (aliceSizes[mid] < y) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return ans;
	}
};

int main(){
    
    return 0;
}