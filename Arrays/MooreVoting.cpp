#include<bits/stdc++.h>
using namespace std;
// majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int bucket;
        for(int i=0; i< nums.size();i++)
        {
            if(cnt == 0)
            {
                bucket = nums[i];
                cnt =1;
            }   
            else if(nums[i] == bucket) cnt++;
            else cnt--;  
        }
        return bucket;
    }
};
int main(){
    
    return 0;
}