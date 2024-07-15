#include<bits/stdc++.h>
using namespace std;

// gitves TLE
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int i=nums[0];
            for(int j=1;j<n-1;j++)
            {
                i= min(i,nums[j]);
                for(int k=j+1;k<n;k++)
                {
                    if(i < nums[k] && nums[k] < nums[j]) return true;
                }
            }
        return false;
    }
};