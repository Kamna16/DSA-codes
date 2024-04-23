#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int maxi = 0;
        int l=0, r=0;
        while(r<n)
        {
            mp[fruits[r]]++;
            if(mp.size()> 2)
            {
                while(mp.size() > 2)
                {
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0)
                        mp.erase(fruits[l]);
                    l++;
                }
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};

int main(){
    
    return 0;
}