#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int mask = 0;
        int longest = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a')
            {
                mask ^= (1 << 0);
            }
            else if(s[i] == 'e')
            {
                mask ^= (1 << 1);
            }
            else if(s[i] == 'i')
            {
                mask ^= (1 << 2);
            }
            else if(s[i] == 'o')
            {
                mask ^= (1 << 3);
            }
            else if(s[i] == 'u')
            {
                mask ^= (1 << 4);
            }

            if(mp.find(mask) != mp.end())
            {
                longest = max(longest,i-mp[mask]);
            }else{
                mp[mask] = i;
            }
        }
        return longest;
    }
};