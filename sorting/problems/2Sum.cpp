#include<bits/stdc++.h>
using namespace std;
// Approach 1 : find = target-arr[i]; --> find in remaining arr after i
// Approach 1 : using map to store elmnt, check in map (find = target-arr[i]) is present

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
    for(int i=0;i<nums.size();i++)
    {
        int curr = nums[i];
        int more = target - nums[i];
        if(mp.find(more) != mp.end())
        {
            return {mp[more], i};
        }
        mp[curr] = i;
    }
    return {-1,-1};
    }
};


// if input is sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int i=1;
        int j= n;
        while(i<j)
        {
            int num = numbers[i-1]+numbers[j-1];
            if( num == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if(num < target) i++;
            else j--;
        }
        return ans;
    }
};