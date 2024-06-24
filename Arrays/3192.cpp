#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> temp(nums);
        int n = temp.size();
        int i=0;
        int count =0;
        while(i<n)
        {
            if(count%2 == 1 && temp[i] == 1) count++;
            if(count%2 == 0 && temp[i] == 0) count++;
            i++;
        }
        return count;
    }
};