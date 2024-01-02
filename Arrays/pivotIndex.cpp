#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum =0;
		int rsum = 0;
		for(int i=0;i<nums.size();i++)
		{
			rsum+= nums[i];
		}
		for(int i=0;i<nums.size();i++)
		{
			rsum -= nums[i];
			if(lsum == rsum)
			{
				return i;
			}
			lsum+= nums[i];
		}
		return -1;
    }
};

int main(){
    
    return 0;
}