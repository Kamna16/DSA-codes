#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) 
    { 
        bool containsOne = false;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) containsOne = true;
            if(nums[i] < 1 || nums[i] > n) nums[i] = 1;
        }
        if(!containsOne) return 1;
        for(int i=0;i<n;i++)
        {
            int idx = abs(nums[i])-1;
            if(nums[idx] < 0) continue;
            nums[idx] = -nums[idx];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    } 
};