#include<iostream>
using namespace std;

int search(int s, int e, int arr[],int key)
{
    if(s <= e){
        int mid = s+(e-s)/2;
        if(arr[mid] == key) return mid;
        if(arr[mid] < key) return search(mid+1,e,arr,key);
        else return search(s,mid-1,arr,key);
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    cout<< search(0,7,arr,9);
    return 0;
}