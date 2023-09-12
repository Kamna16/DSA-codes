//  Find First and Last Position of Element in Sorted Array
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target, bool findStartIndex)
    {
        int ans = -1;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e)
        {
            int mid = s +(e-s)/2;
            if(nums[mid] < target)
            {
                s= mid+1;
            }
            else if(nums[mid] > target)
            {
                 e= mid-1;
            }
            else
            {
                ans = mid;
                if(findStartIndex)
                {
                    e = mid-1;
                }else s = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        bool isstart = true;
        int start = search(nums,target,isstart);
        isstart = false;
        int end = search(nums,target,isstart);

        ans[0] = start;
        ans[1] = end;
        return ans;
    }
};

int main(){
    
    return 0;
}