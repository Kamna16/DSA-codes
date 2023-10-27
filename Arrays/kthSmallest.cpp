#include<bits/stdc++.h>
using namespace std;
// nlogn
int kthSmallest(int arr[], int l, int r, int k) {
        
        sort(arr, arr+r+1);
        
        return arr[k-1];
}
// nlogk
int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> pq;
        for(int i=l;i<=r;i++)
        {
           pq.push(arr[i]);
           if(pq.size() > k)
           {
               pq.pop();
           }
        }
        return pq.top();
}

int main(){
    
    return 0;
}