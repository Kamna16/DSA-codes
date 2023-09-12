#include<bits/stdc++.h>
using namespace std;
int elementThatAppearsOnce(vector<int> arr) {
int n = arr.size();
	vector<int> freq(32,0);
	for(int i=0;i<n;i++)
	{
		int curr_num= arr[i];
		for(int j=0;j<32;j++)
		{
			if(((curr_num>>j) &1) != 0){
				freq[j]++;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<32;i++)
	{
		if((freq[i]%3) !=0)
		{
			ans |=(1<<i);
		}
	}
	return ans;
	
}

int main(){
    
    return 0;
}