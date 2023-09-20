#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> nextSmallerElement(vector<int>& nums) {
		int n = nums.size();
		stack<int> st;
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int currElem = nums[i];
            // can currElem can as next greater elem for prev elements
            while(!st.empty() && currElem < nums[st.top()])
            {
                ans[st.top()] = currElem;
                st.pop();
            }
            st.push(i);
        }
        // for all remaining elements answer is -1 
        while(!st.empty())
        {
            int topElem = st.top();
            st.pop();
            ans[topElem] = -1;
        }
        return ans;
	}
};

int main(){
    
    return 0;
}