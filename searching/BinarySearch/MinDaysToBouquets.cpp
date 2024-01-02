#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleSol(vector<int>& bloomDay, int mid, int m, int k, int n) {
        int flowerCount = 0;
        int bouquetCount = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                if (flowerCount + 1 == k) {
                    flowerCount = 0;
                    bouquetCount++;
                } else {
                    flowerCount++;
                }

                if (bouquetCount == m) {
                    return true;
                }
            } else {
                flowerCount = 0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxDay = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            maxDay = max(maxDay, bloomDay[i]);
        }

        int low = 1, high = maxDay;
        int mid = low + (high-low)/2;
        int ans = -1;
        while (low <= high) {
            if (isPossibleSol(bloomDay, mid, m, k, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            mid = low + (high-low)/2;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}