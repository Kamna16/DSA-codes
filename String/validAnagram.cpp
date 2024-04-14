#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/valid-anagram/submissions/1229125588/
class Solution {
public:
    bool isAnagram(string s, string t) {
        // find if t is anagram of s 
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp1, mp2;
        int n = s.size();
        for(char c: s)
        {
            mp1[c]++;
        }
        for(char c: t)
        {
            mp2[c]++;
        }
        for(auto &i: mp1){
            char ch = i.first;
            if(mp2.find(ch) == mp2.end() || mp1[ch] != mp2[ch]) return false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}