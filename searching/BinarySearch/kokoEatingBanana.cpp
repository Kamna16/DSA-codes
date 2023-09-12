#include<bits/stdc++.h>
using namespace std;

int countTotal(vector<int>& piles, int hourly)
{
    int total =0;
    for(int i=0;i<piles.size();i++)
    {
        total+= ceil((double)piles[i]/(double)hourly);
    }
    return total;
}
int maxi(vector<int> &piles)
{
    int maxim = piles[0];
    for(int i=1 ;i< piles.size();i++)
    {
        maxim = max(maxim, piles[i]);
    }
    return maxim;
}
int minimumRateToEatBananas(vector<int> piles, int h) {
        int low =1;
        int high = maxi(piles);
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int totalhrs = countTotal(piles,mid);
            if(totalhrs <=h)
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
}

int main(){
    
    return 0;
}