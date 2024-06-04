#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
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