#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// this function returns the index value if target
    int search(vector<int>& nums, int target, bool findStartIndex)
    {
        int ans =-1;
        int s =0;
        int e=nums.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == target)
            {
                // potential answer is found
                ans = mid;
                if(findStartIndex)
                {
                    // the answer may lie on left
                    e = mid-1;
                }
                else{
                    // the answer may lie on right
                    s = mid+1;
                }

            }
            else if(nums[mid]< target)
            {
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        // check the first occurence of target
        int startvalue = search(nums,target,true);
        // check the last occurence of target
        int endvalue = search(nums,target,false);

        ans[0] = startvalue;
        ans[1] = endvalue;

        return ans;
    }
};

int main(){
    
    return 0;
}