#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        string ans;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i] != ')')
            {
                st.push(s[i]);
            }
            else{
                string temp = "";
                while(!st.empty() && st.top() != '(')
                {
                    temp += st.top();
                    st.pop(); 
                }
                st.pop();
                for(auto i : temp)
                {
                    st.push(i);
                }
            }
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};