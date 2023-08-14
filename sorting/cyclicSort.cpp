#include<bits/stdc++.h>
using namespace std;

void sort(int arr[],int n)
{
    int i=0;
    while(i<n)
    {
        int correctInd = arr[i]-1;
        if(i != correctInd)
        {
            swap(arr[i],arr[correctInd]);
        }else i++;
    }  
}
// void sort(int arr[],int n)
// {
//     int i=0;
//     while(i<n)
//     {
//         int correctInd = arr[i]-1;
//         if(arr[i] != arr[correctInd])
//         {
//             swap(arr[i],arr[correctInd]);
//         }else i++;
//     }  
// }

int main(){
    int arr[] = {5,4,3,2,1};
    sort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}