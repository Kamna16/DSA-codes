#include<iostream>
#include<vector>
// https://leetcode.com/problems/find-in-mountain-array/
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e= arr.size()-1;
        while(s<e)
        {
            int mid = s+(e-s)/2;
            // in the ascending part of the array
            if(arr[mid] < arr[mid+1])
            {
                s = mid+1;
            }
            // descending part of the array
            else
            {
                // this may be the answer but look at left  ---> end != mid-1
                e = mid;
            }
        }
        // in the end start == end pouinting to the larger number
        return s; // or you can return e
    }
};

int main(){
    
    return 0;
}