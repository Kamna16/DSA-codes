#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<int,int> mp;
        int sum =0;
        int assign =2;
        for(char ch : word)
        {
            if(assign > 9) assign =2;

            mp[assign]++;
            sum+= mp[assign];
            assign++;
        }
        return sum;
    }
};

// can be used if freq > 1
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        for(char ch : word)
        {
            mp[ch-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        int sum =0;
        for(int i=0;i<26;i++)
        {
            int freq = mp[i];
            int press = i/8+1;
            sum+= press * freq;
        }
        return sum;
    }
};