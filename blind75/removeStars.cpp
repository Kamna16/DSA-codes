#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n= s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] == '*') st.pop();
            else st.push(s[i]);
        }
        vector<char> v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        s = "";
        for(int i=v.size()-1;i>=0;i--)
        {
            s += v[i];
        }
        return s;
    }
};

int main(){
    
    return 0;
}