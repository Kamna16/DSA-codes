#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        int count=0;
        for(auto i : freq)
        {
            if(i.second > 1)
            {
                count += (i.second * (i.second -1))/2;// x * (x-1)/2
            }
        }
        return count;
    }
};