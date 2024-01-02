#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxOfSubArray(vector<int>& arr, int k) {
        vector<int> ans;
        queue<int> q;
        int maxi = INT_MIN;
        int i = 0, j = 0;
        while (j < k) {
            if (arr[j] > maxi) {
                maxi = arr[j];
            }
            j++;
        }
        ans.push_back(maxi);
        while (j < arr.size()) {
            if (arr[j] > maxi) {
                maxi = arr[j];
            } else {
                if (arr[i] == maxi) {
                    maxi = INT_MIN;
                    for (int x = i + 1; x <= j; x++) {
                        if (arr[x] > maxi) {
                            maxi = arr[x];
                        }
                    }
                }
            }
            ans.push_back(maxi);
            i++;
            j++;
        }
        return ans;
    }
};
int main(){
    
    return 0;
}