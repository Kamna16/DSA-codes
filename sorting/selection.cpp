#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        int min_index = arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(min_index < arr[j]) min_index = arr[j];
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