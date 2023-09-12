#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void incExc(vector<int> arr,vector<vector<int>> &ans,int i, vector<int> opt)
	{
		//base case;
		if(i>= arr.size())
		{
			ans.push_back(opt);
			return;
		}
		//exclude
		incExc(arr,ans,i+1,opt);
		// include
		int element= arr[i];
		opt.push_back(element);
		incExc(arr,ans,i+1,opt);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> op;
		int index=0;
		incExc(nums,ans,index,op);
		return ans;
	}
};
int main(){
    
    return 0;
}