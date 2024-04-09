#include<bits/stdc++.h>

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        long long count=0;
        for(int i=0;i<n;i++)
        {
            long long cnt=0;
            int curr = nums[i];
            while(curr)
            {
                cnt++;
                curr = curr/10;
            }
            if(cnt%2 ==0) count++;
        }
        return count;
    }
};

int main() {

    return 0;
}
