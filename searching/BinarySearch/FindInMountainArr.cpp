#include<bits/stdc++.h>
using namespace std;
// leetcode hard :https://leetcode.com/problems/find-in-mountain-array/description/

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
int peakIndexInMountainArray(MountainArray &arr) {
        int s=0;
        int e= arr.length()-1;
        while(s<e)
        {
            int mid = s+(e-s)/2;
            if(arr.get(mid) < arr.get(mid+1))
            {
                s = mid+1;
            }
            else
            {
                e = mid;
            }
        }
        return s;
    }
    int orderAgnosticBS(MountainArray &arr,int target, int s, int e)
    {
        bool isAsc = arr.get(s) < arr.get(e);
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(arr.get(mid) == target) return mid;
            if(isAsc)
            {
                if(target < arr.get(mid))
                {
                    e = mid-1;
                }
                else s = mid+1;
            }
            else
            {
                if(target > arr.get(mid))
                {
                    e = mid-1;
                }
                else s = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // find the peak index
        int peak = peakIndexInMountainArray(mountainArr);
        // search in ascending order i.e left half
        int firstTry = orderAgnosticBS(mountainArr,target,0,peak);
        if(firstTry != -1)
        {
            return firstTry;
        }
    
        // try to search in second half
        return orderAgnosticBS(mountainArr, target, peak+1, mountainArr.length()-1);
    }
};
int main(){
    
    return 0;
}