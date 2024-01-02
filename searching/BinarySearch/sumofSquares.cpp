#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int l =0;
		int r=sqrt(c);
		while(l<=r)
		{
			long long total = (long long)l * l + (long long)r * r;
			if( total == c) return true;
			else if(total < c) l++;
			else r--;
		}
		return false;
    }
};

int main(){
    
    return 0;
}