#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> ans;
		unordered_map<int,int> m ={};// for frequency
		int n = nums.size();

		// min heap
		priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> q;

		for(int i=0;i<n;i++)
		{
			m[nums[i]]++; // storing frequency of every elements
		}
		// traversing the map
		for(auto i=m.begin(); i!=m.end(); i++)
		{
			q.push({i->second, i->first});
			if(q.size()>k)
			{
				q.pop();
			}
		}
		// push the top elements in ans vector
		while(q.size()> 0)
		{
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
	}
};

int main(){
    
    return 0;
}