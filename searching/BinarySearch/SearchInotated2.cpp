#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(nums[mid]==target) return true;
            if(nums[l] == nums[mid] && nums[h] == nums[mid])
            {
                l++;
                h--;
                continue;
            }
            //left sorted
            if(nums[l]<=nums[mid])
            {
                if(target>=nums[l] && target<=nums[mid])
                {
                    h=mid-1;
                }else l=mid+1;
            }else{
                if(target>=nums[mid] && target<=nums[h])
                {
                    l=mid+1;
                }else h=mid-1;
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}