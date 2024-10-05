#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

void BubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {7,6,5,4,3,2,1};
    BubbleSort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i];
    }
    
    return 0;
}