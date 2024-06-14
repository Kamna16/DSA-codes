#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        string dummy = s+s;
        int i=0;
        int sz = dummy.length();
        while(i < n)
        {
            string curr = dummy.substr(i,n);
            if(curr == goal) return true;
            i++;
        }
        return false;
    }
};