#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = nums.size(), ans = 0;

        for (int i=0;i<32;++i){
            int sum = 0;
            for (int num :  nums){
                sum += ((num >> i) & 1);
            }
            sum %= 3;
            ans |= sum << i;
        }
		return ans;
		
	}
};

int main(){
    
    return 0;
}