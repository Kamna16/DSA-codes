#include<bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack<long long> st;
        vector<long long> ans(n);
        for(int i=0; i<n; i++)
        {
            int currElem = arr[i];
            // can currElem can as next greater elem for prev elements
            while(!st.empty() && currElem > arr[st.top()])
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