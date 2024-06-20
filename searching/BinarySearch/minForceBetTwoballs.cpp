#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool minForce(int mid,vector<int>& position, int m)
    {
        int prev = position[0];
        int countBalls = 1;
        for(int i=1;i<position.size();i++)
        {
            if((position[i]-prev) >= mid)
            {
                prev = position[i];
                countBalls++;
            }
            if(countBalls == m) return true;
        }
        return countBalls==m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxi = *max_element(position.begin(),position.end());
        int l=1;
        int r=maxi;
        int ans = 0;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(minForce(mid,position,m))
            {
                ans = mid;
                l=mid+1;
            }else r = mid-1;
        }
        return ans;
    }
};