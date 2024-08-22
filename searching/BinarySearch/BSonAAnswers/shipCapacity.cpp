#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
int reqDay(vector<int> &weights,int cap)
{
    int days =1;
    int load =0;
    for(int i=0;i<weights.size();i++)
    {
        if(weights[i]+load>cap)
        {
            days+=1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int d) {
        int n = weights.size();
    int low = INT_MIN;
    int high = 0;
    for(int i=0;i<n;i++)
    {
        if(low< weights[i]) low = weights[i];
        high += weights[i];
    }

    while(low<=high)
    {
        int mid = low+(high-low)/2;
        int reqDays = reqDay(weights,mid);
        if(reqDays <= d)
        {
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    //opposite polarity concept
    return low;
    }
};

int main(){
    
    return 0;
}