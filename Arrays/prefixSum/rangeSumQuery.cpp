#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> arr;

    NumArray(vector<int>& nums) {
        arr.resize(nums.size());
        arr[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            arr[i] = arr[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left > 0) return arr[right] - arr[left-1];
        return arr[right];
    }
};
