#include<bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;
        
        // Count the number of 1s in the array
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) oneCount++;
        }

        // If there are no 1s or all are 1s, no swaps needed
        if (oneCount == 0 || oneCount == n) return 0;

        // Duplicate the array to handle the circular nature
        nums.insert(nums.end(), nums.begin(), nums.end());

        // Initialize the window with the first oneCount elements
        int zeroCount = 0;
        for(int i = 0; i < oneCount; i++) {
            if(nums[i] == 0) zeroCount++;
        }

        // Use the sliding window technique to find the minimum zeros in any window of size oneCount
        int minSwaps = zeroCount;
        for(int i = oneCount; i < 2 * n; i++) {
            if(nums[i - oneCount] == 0) zeroCount--; // Slide the window forward
            if(nums[i] == 0) zeroCount++;
            minSwaps = min(minSwaps, zeroCount);
        }

        return minSwaps;
    }
};
