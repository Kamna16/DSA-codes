#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1= INT_MAX;
        int num2= INT_MAX;
        int num3= INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int num3 = nums[i];
            if(num3 <= num1) num1 = num3;
            else if(num3 <= num2) num2 = num3;
            else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}