#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        int ans =0;
        int diff = INT_MAX;
        sort(arr.begin(),arr.end());
        int i=0;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k = n-1;
            while(j<k)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                if(sum==target) return sum;
                if(abs(target-sum)< diff)
                {
                    diff = abs(target-sum);
                    ans = sum;
                }
                
                if(sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};