#include<bits/stdc++.h>
// search if that element appear anywhere else --> n^2
// Sorting --> nlogn
// Hashmap --> n
// Xor --> n

using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int Xor=0;
		int n = nums.size();
		for(int i=0;i<n;i++)
		{
			Xor ^= nums[i];
		}
		return Xor;
	}
};

int main(){
    
    return 0;
}