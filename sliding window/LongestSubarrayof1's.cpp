#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocnt=0;
        int i=0, j=0, n =nums.size();
        int ans =0;
        for(;j<n;j++)
        {
            if(nums[j]==0) zerocnt++;
            for(;zerocnt>1;i++)
            {
                if(nums[i] ==0) zerocnt--;
            }
            ans = max(ans,j-i+1);
        }
        return ans-1;
    }
}; 
int main(){
    
    return 0;
}