#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0;
        int j = nums.size()-1;
        int count=0;
        while(i<j)
        {
            if(nums[i]+nums[j] == k)
            {
                count++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j] > k)
            {
                j--;
            }
            else if(nums[i]+nums[j] < k)
            {
                i++;
            }
        }
        return count;
    }
};

int main(){
    
    return 0;
}