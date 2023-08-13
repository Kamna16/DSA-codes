#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int secondSmallest(vector<int>& nums) {
		int smallest = nums[0];
		int secSmall = INT_MAX;
		for( int i=1; i< nums.size();i++)
		{
			if (nums[i] < smallest) {
                secSmall = smallest;
                smallest = nums[i];
            } else if (nums[i] > smallest && nums[i] < secSmall) {
                secSmall = nums[i];
            }
		}
		return secSmall;
	}
};

int main(){
    
    return 0;
}