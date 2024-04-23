#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            vector<long long> merged;
            int i = 0, j = 0;
        
            while (i < n && j < m ){
                if (arr1[i] <= arr2[j]) {
                    merged.push_back(arr1[i]);
                    i++;
                } else {
                    merged.push_back(arr2[j]);
                    j++;
                }
            }
        
            while (i < n) {
                merged.push_back(arr1[i]);
                i++;
            }
        
            while (j < m) {
                merged.push_back(arr2[j]);
                j++;
            }
            for(int i=0;i<n;i++)
            {
                arr1[i] = merged[i];
            }
            for(int i=n;i<merged.size();i++)
            {
                arr2[i-n] = merged[i];
            }
        } 
};


vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
     vector<int> arr1 = {1, 2, 3};
     vector<int> arr2 = {4, 5, 6};

    vector<int> result;
    result = mergeArrays(arr1, arr2);
    for (int x : result)
        cout << x << " ";

    return 0;
}