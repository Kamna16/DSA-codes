// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

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