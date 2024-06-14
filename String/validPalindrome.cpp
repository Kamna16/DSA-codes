#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(int j=0;j<t.size();j++)
        {
            if(mp.find(t[j]) != mp.end())
            {
                mp[t[j]]--;
            }else return false;
        }
        for(auto i : mp)
        {
            if(i.second != 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true; // Handle empty string case
        string r = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) {
                r += tolower(s[i]);
            }
        }
        // s still contains puntuations and spaces
        int left = 0, right = r.size() - 1;
        while (left < right) {
            if (r[left] != r[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};

int main(){

    string s = "s!jh: js 'dgh";
    if(s.empty()) return true; // Handle empty string case
        string r = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) {
                r += tolower(s[i]);
            }
        }
        cout<< "r : " << r;
        int left = 0, right = r.size() - 1;
        while (left < right) {
            if (r[left] != r[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    return 0;
}