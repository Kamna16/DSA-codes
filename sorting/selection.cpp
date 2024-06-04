#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int min_index = arr[i];
        for(int j=i;j<=n-1;j++)
        {
            if(min_index > arr[j]) min_index = arr[j];
        }
        swap(arr[i], arr[min_index]);
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