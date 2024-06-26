#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        int sum = 0;
        for(int p : piles)
        {
            pq.push(p);
            sum+=p;
        }
        for(int i=0;i<k;i++)
        {
            int maxElem = pq.top();
            pq.pop();
            int remove = maxElem/2;
            sum -= remove;
            pq.push(maxElem-remove);
        }
        return sum;
    }
};