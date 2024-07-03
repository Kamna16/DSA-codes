#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
        ans[0]= pref[0];
        for(int i=1;i<pref.size();i++)
        {
            ans[i] = pref[i]^pref[i-1];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // vector<int> ans(pref.size());
        // ans[0]= pref[0];
        for(int i=pref.size()-1;i>=1;i--)
        {
            pref[i] = pref[i]^pref[i-1];
        }
        return pref;
    }
};