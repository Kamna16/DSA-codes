#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		deque<int> q;
		vector<int> ans;
		// insert first  3 elements
		for(int i=0;i<k;i++)
		{
			// if last element in queue is less than current element just remove it
			while(q.size() !=0 && nums[q.back()] <= nums[i])
			{ 
				q.pop_back();
			}
			q.push_back(i);
		}
		ans.push_back(nums[q.front()]);
		for(int i=k;i<n;i++)
		{
			// if the element is old remove it
			if(i-q.front() >= k) q.pop_front();
			while(q.size() !=0 && nums[q.back()] <= nums[i])
			{
				q.pop_back();
			}
			q.push_back(i);
			ans.push_back(nums[q.front()]);
		}
		return ans;

	}
};
int main(){
    
    return 0;
}