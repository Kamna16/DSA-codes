#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int findIndex =-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                findIndex = i-1;
                break;
            }
        }
        int swapInd = -1;
        if(findIndex != -1)
        {
            for(int j=n-1;j>findIndex;j--)
            {
                if(nums[j]>nums[findIndex])
                {
                    swapInd = j;
                    break;
                }
            }
            swap(nums[findIndex],nums[swapInd]);
        }
        reverse(nums.begin()+findIndex+1,nums.end());
    }
};
