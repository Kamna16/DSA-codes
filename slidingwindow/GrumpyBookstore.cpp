#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        // cal for first m minutes
        int total = 0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i] == 0)
                total += customers[i];
        }
        int unsatisfied = 0;
        for(int i=0;i<minutes;i++)
        {
            unsatisfied += customers[i]*grumpy[i];
        }
        int maxi= unsatisfied;
        int i=0;
        int j= minutes;
        // calulate max unsatisfied in whole array
        while(j<n)
        {
            unsatisfied += customers[j]*grumpy[j];
            unsatisfied -= customers[i]*grumpy[i];

            maxi = max(maxi,unsatisfied);

            j++;
            i++;
        }
        
        return total+maxi;
    }
};