#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		int top=-1;
		for(int i=0;i<s.length();i++)
		{
			if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				top++;
				stack.push_back(s[i]);
			}
			else {
				if(stack.empty()) return false;

				char top = stack.back();

				stack.pop_back();

				if(s[i] == ')' && top != '(') return false;
				if(s[i] == '}' && top != '{') return false;
				if(s[i] == ']' && top != '[') return false;
			}
		}
		return stack.empty();
	}
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
		for(int i=0;i<s.length();i++)
		{
			if(st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				st.push(s[i]);
			}
			else {
                if(s[i] == ')')
				{
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                if(s[i] == '}')
				{
                    if(st.top() == '{') st.pop();
                    else return false;
                }
                if(s[i] == ']')
				{
                    if(st.top() == '[') st.pop();
                    else return false;
                }
			}
		}
		return st.empty();
    }
};