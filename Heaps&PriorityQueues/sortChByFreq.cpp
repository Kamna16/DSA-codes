#include<bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    static bool myComparator(pair<char,int> a, pair<char,int> b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        priority_queue<pair<char,int>> pq;
        unordered_map<char,int> mp;
        for(char c : s)
        {
            mp[c]++;
        }
         vector<pair<char, int>> freqVec(mp.begin(), mp.end());
        sort(freqVec.begin(), freqVec.end(), myComparator);
        string ans = "";
        for(auto p :freqVec)
        {
            for(int i=0;i<p.second;i++)
            {
                ans+= p.first;
            }
        }
        return ans;
    }
};

// using heap
class Solution {
public:
    typedef pair<char,int> p;
    struct lambda {
        bool operator()(p &p1, p &p2)
        {
            return p1.second<p2.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<p, vector<p> , lambda> pq;
        unordered_map<char,int> mp;
        for(char c : s)
        {
            mp[c]++;
        }
        for(p i : mp)
        {
            pq.push({i.first,i.second});
        }
        string ans = "";
        while(!pq.empty())
        {
            p temp = pq.top();
            pq.pop();
            ans += string(temp.second, temp.first);
        }
        return ans;
    }
};