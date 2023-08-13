#include<iostream>
#include<vector>
using namespace std;
bool isSorted(vector<int> &arr,int index)
{
    if(index == arr.size()-1){
        return true;
    }
    return arr[index] < arr[index +1] && isSorted(arr,index+1);
}

int main(){
    vector<int> arr = {1,2,9,4,5};
    cout<<isSorted(arr,0);
    return 0;
}