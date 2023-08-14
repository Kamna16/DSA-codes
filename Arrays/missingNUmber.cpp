#include<bits/stdc++.h>
using namespace std;
// cyclic sort
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        while(i<n)
        {
            int corr = arr[i];
            if(arr[i] < n && arr[i] != arr[corr])
            {
                swap(arr[i],arr[arr[i]]);
            }else i++;
        } 
        for(int i=0;i<n;i++){
            if(arr[i]!=i)
            {
                return i;
            }
        }
        return n;
    }
};

int main(){
    
    return 0;
}