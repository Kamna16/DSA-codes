#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        while(i<n)
        {
            if(arr[i]>0 && arr[i] <=n && arr[i] != arr[arr[i]-1])
            {
                swap(arr[i],arr[arr[i]-1]);
            }else i++;
        }  
        for(int i=0;i<n;i++)
        {
            if(arr[i] != i+1)
            {
               return i+1;
            }
        }
        return n+1;
    }
};

int main(){
    
    return 0;
}