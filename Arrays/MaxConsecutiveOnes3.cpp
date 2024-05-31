#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi= 0;
        int l=0,r=0;
        int zeros=0;
        while(r<n)
        {
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }else{
                maxi= max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};

int main(){
    
    return 0;
}