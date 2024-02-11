#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int i=0;
        int j=0;
        int ans= 0;
        int zerocnt=0;
        while(j<n)
        {
            if(nums[j]==0) zerocnt++;
             while(zerocnt > k)
            {
                if(nums[i]==0) zerocnt--;
                i++;
            }   
            ans= max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}