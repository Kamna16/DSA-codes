#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            int count=0;
            int num=i;
            while(num!=0)
            {
                if(num%2 == 1) count++;
                num = num/2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// approach 2
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++)
        {
            if(i%2==0) ans[i]=ans[i/2];
            else ans[i]=ans[i/2]+1;
        }
        return ans;
    }
};