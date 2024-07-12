#include<bits/stdc++.h>
using namespace std;

// using stack 
// 1. iterate and remove max value string
// 2. iterate and remove min value string
// 3. Add them to answer
class Solution {
public:
    int pointsForString(string &s, string target, int point)
    {
        int points = 0;
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.size() == 0)
            {
                st.push(s[i]);
            }else{
                if(s[i] == target[1] && st.top() == target[0]){
                    st.pop();
                    points += point;
                }else{
                    st.push(s[i]);
                }
            }
        }

        s="";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return points;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2="ba";
        if(x<y) swap(s1,s2), swap(x,y);

        return pointsForString(s,s1,x) + pointsForString(s,s2,y);
    }
};


// using two pointer
class Solution {
public:
    int pointsForString(string &s, string target, int point)
    {
        int points = 0;
        int i=0, j=0;
        while(j<s.size())
        {
            s[i] = s[j];
            i++;
            if(i >= 2 &&s[i-1]== target[1] && s[i-2] == target[0])
            {
                i = i-2;
                points += point;
            } 
            j++;
        }
        s.erase(s.begin()+i, s.end());
        return points;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2="ba";
        if(x<y) swap(s1,s2), swap(x,y);

        return pointsForString(s,s1,x) + pointsForString(s,s2,y);
    }
};