#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int findSecondLargest(int n, vector<int> &arr)
{
    int large = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > large)
        {
            large= arr[i];
        }

    }
    int secLarge = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > secLarge && arr[i] != large)
        {
            secLarge= arr[i];
        }
    }
    if(secLarge == INT_MIN) secLarge=-1;
    return secLarge;
}
int findSecondLargest(int n, vector<int> &arr)
{
    int large = arr[0];
    int seclarge = -1;
    for(int i=1;i<n;i++){
        if(arr[i] > large)
        {
            seclarge= large;
            large= arr[i];
        }
        if(arr[i] > seclarge)
        {
            seclarge= arr[i];
        }

    }
    
    return seclarge;
}

int main(){
    
    return 0;
}