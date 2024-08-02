#include<bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0; 
        int maxSum = INT_MIN;
        for(int i=0; i<nums.size();i++)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum< 0) sum =0;

        }
        return maxSum;
    }
};

int main(){
    
    return 0;
}