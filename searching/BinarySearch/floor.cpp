#include<iostream>
using namespace std;

int ceiling(int arr[],int n, int target)
{
    int s =0;
    int e = n-1;
    while(s<=e)
    {
        int mid = s +(e-s)/2;
        if(arr[mid] < target) s= mid+1;
        else if(arr[mid] > target) e= mid-1;
        else return mid;
    }
    return e;
}

int main(){
    int arr[] = {2,3,5,9,14,16,18};
    cout<<ceiling(arr,7,15);
    return 0;
}