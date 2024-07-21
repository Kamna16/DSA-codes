#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int count =0;
        for(auto p : mp)
        {
            while(p.second >= 3) p.second -= 2;
            count += p.second;
        }
        return count;
    }
};