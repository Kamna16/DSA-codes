#include<bits/stdc++.h>
using namespace std; //self

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,candies[i]);
        }
        vector<bool> ans(n);
        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies >= maxi)
            {
                ans[i] = true;
            }
            else ans[i] = false;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}