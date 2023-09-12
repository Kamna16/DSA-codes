#include<bits/stdc++.h>
using namespace std;
// cycle sort
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        while(i<n)
        {
            int correctInd = arr[i]-1;
            if(arr[i] != arr[correctInd])
            {
                swap(arr[i],arr[correctInd]);
            }else i++;
        }  
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != i+1)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
int findDuplicate(vector<int> &arr, int n){
        int i=0;
        while(i<n)
        {
            if( arr[i] != i+1)
            {
                int correct = arr[i]-1;
                if(arr[i] != arr[correct])
                {
                    swap(arr[i],arr[correct]);
                }else return arr[i];
            }
            else i++;
        }

        return -1;
}

int main(){
    
    return 0;
}