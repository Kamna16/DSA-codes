#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high) return;
        
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
    
    public:
    int partition(int arr[], int low, int high)
    {
       int p = arr[high];
       int i = low-1;
       int j=low;
       while(j<high)
       {
          if(arr[j] < p)
          {
              i++;
              swap(arr[i],arr[j]);
          }
          j++;
       }
       swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};