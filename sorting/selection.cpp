#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort

void selectionSort(int arr[], int n)
    {
       for(int i=0;i<n-1;i++)
       {
           int mini = i;
           for(int j=i+1;j<n;j++)
           {
               if(arr[j]<arr[mini]) mini = j;
           }
           swap(arr[mini],arr[i]);
       }
    }

int main(){
    int arr[] = {7,6,5,4,3,2,1};
    selectionSort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i];
    }
    return 0;
}