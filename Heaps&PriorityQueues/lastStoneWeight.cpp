#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
		for(int &stone : stones)
		{
			pq.push(stone);
		}
		while(pq.size()>1)
		{
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			pq.push(abs(a-b));
		}
		return pq.top();
    }
};