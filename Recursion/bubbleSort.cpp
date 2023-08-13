#include<iostream>
using namespace std;
void bubble(int arr[],int pass, int i)
{
    if(pass == 0) return;
    if(i < pass){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
        bubble(arr,pass,i+1);
    }else{
        bubble(arr, pass-1,0);
    }
}

int main(){
    int arr[] = {5,3,4,2,1,1};
    bubble(arr,6-1,0);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}