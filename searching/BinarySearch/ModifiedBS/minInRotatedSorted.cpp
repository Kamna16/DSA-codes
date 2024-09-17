#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e=n-1;
        while(s<e)
        {
            int m = s+(e-s)/2;
            if(nums[m] > nums[e])
            {
                s = m+1;
            }else e = m;
        }
        return nums[e];
    }
};

int findMin(vector<int>& nums)
{
	int low=0;
        int high = nums.size()-1;
        int mini = INT_MAX;
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            if(nums[low] <= nums[mid])
            {
                mini = min(nums[low], mini);
                low=mid+1;
            }
            else{
                mini = min(nums[mid], mini);
                high = mid-1;
            }
        }

        return mini;
}
int main(){
    
    return 0;
}