#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> c_p(n);
        for(int i=0;i<n;i++)
        {
            c_p[i] = {capital[i],profits[i]};
        }
        sort(c_p.begin(),c_p.end());// sort based on capital value
        priority_queue<int> pq;
        int i=0;
        while(k--)
        {
            while(i<n && c_p[i].first <=w)
            {
                pq.push(c_p[i].second);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};