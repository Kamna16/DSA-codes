#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-chunks-to-make-sorted/description/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int count =0;
        for(int i=0;i<n;i++)
        {
            maxi= max(arr[i],maxi);
            if(i == maxi) count++;
        }
        return count;
    }
};

int main(){
    
    return 0;
}