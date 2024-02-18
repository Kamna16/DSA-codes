#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix[n];
        int suffix[n];
        vector<int> ans(n);

        prefix[0] = 1;
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        suffix[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i=0;i<ans.size();i++)
        {
            ans[i] = prefix[i]*suffix[i];
        }
        return ans;
    }
};

int main(){
    
    return 0;
}