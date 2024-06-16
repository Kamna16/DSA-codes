#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxReach =0;
        int patch =0;
        int l = nums.size();
        int i=0;
        while(maxReach<n)
        {
            if(i < l && nums[i] <= maxReach+1)
            {
                // no patching
                maxReach += nums[i];
                i++;
            }else{
                maxReach += maxReach+1;
                patch++;
            }
        }
        return patch;
    }
};

int main(){
    
    return 0;
}