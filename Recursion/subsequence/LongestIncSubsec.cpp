#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
int solve(vector<int>& arr, int n,int curr,int prev)
{
    // base case
    if(curr == n) return 0;
    // include
    int pick =0;
    if(prev == -1 || arr[curr] > arr[prev])
    {
        pick = 1+ solve(arr,n,curr+1,curr);
    }
    // exclude
    int notPick = 0+ solve(arr,n,curr+1,prev);

    return max(pick,notPick);
}
    int lengthOfLIS(vector<int>& nums) {
        int curr =0;
        int prev =-1;
        int n = nums.size();
        return solve(nums,n,curr,prev);

    }
};

int main(){
    
    return 0;
}