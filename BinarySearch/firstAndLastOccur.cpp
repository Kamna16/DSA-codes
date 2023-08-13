#include <bits/stdc++.h> 
#include <vector> 
using namespace std;
int firstocc(vector<int>& arr, int n, int k)
{
    int low = 0;
    int high = n-1;
    int first = -1;
    // lowerbound
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid] == k)
        {
            first = mid;
            high = mid -1;
        }
        else if(arr[mid] < k){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return first;
}
int lastocc(vector<int>& arr, int n, int k)
{
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid] == k)
        {
            last = mid;
            low = mid +1;
        }
        else if(arr[mid] < k){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = -1;
    int last = -1;
    first = firstocc(arr,n,k);
    if(first == -1) return {-1,-1};
    last = lastocc(arr,n,k);
    
    return {first,last};
}