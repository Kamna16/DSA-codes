#include<bits/stdc++.h>
using namespace std;

//brute force
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answers(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int count =1;
                while(temperatures[j]<=temperatures[i]) count++;
                answers.push_back(count);
            }
        }

        return answers;
    }
}; // -> TLE

// optimal -- using monotonic stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()] ) st.pop();
            if(st.empty())
            {
                answer[i]=0;
            }else{
                answer[i] = st.top() - i;
            }
            st.push(i);
        }
        return answer;
    }
};


int main(){
    
    return 0;
}