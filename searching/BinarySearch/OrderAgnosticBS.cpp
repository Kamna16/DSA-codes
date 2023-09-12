#include<iostream>
#include<vector>
using namespace std;
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e= arr.size()-1;
        while(s<e)
        {
            int mid = s+(e-s)/2;
            if(arr[mid] < arr[mid+1])
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
    int orderAgnosticBS(vector<int>& arr,int target, int s, int e)
    {
        bool isAsc = arr[s] < arr[e];
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] < target)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peakIndexInMountainArray(mountainArr);
        int firstTry = orderAgnosticBS(mountainArr,target,0,peak);

    }
    if(firstTry != -1)
    {
        return firstTry;
    }
    // try to search in second half
    return orderAgnosticBS(mountainArr, target, peak+1, mountainArr.size()-1);
};

int main(){
    
    return 0;
}