#include<iostream>
using namespace std;

class Solution {
public:
    int isSub(int i,int j,string s,string t)
    {
        if(i >= s.length() || j >= t.length()) return 0;

        if(s[i] == t[j])
        {
            return  1 + isSub(i+1,j+1,s,t);
        }
        else return isSub(i,j+1,s,t);
    }
    bool isSubsequence(string s, string t) {
        int ans = isSub(0,0,s,t);
        if(ans == s.length()) return true;
        else return false;
    }
};

int main(){
    
    return 0;
}