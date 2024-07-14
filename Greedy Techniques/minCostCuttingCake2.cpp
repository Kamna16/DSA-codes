#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x = horizontalCut.size();
        int y = verticalCut.size();
        int hp=1,vp=1;
        long long cost=0;
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        int i=0,j=0;
        while(i<x && j<y)
        {
            if(horizontalCut[i] >= verticalCut[j])
            {
                cost += horizontalCut[i]*vp;
                hp++;
                i++;
            }else{
                cost += verticalCut[j]*hp;
                vp++;
                j++;
            }
        }
        while(i<x)
        {
            cost += horizontalCut[i]*vp;
            hp++;
            i++;
        }
        while(j<y)
        {
            cost += verticalCut[j]*hp;
            vp++;
            j++;
        }
        return cost;
    }
};