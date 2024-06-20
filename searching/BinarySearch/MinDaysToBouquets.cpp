#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int day,vector<int>& bloomDay,int m,int k)
    {
        int consecutive_count =0;
        int bouquets =0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                consecutive_count++;
            }else{
                consecutive_count= 0;
            }
            if(consecutive_count == k)
            {
                bouquets++;;
                consecutive_count=0;
                if (bouquets >= m) {
                    return true;
                }
            }
        }
        if(bouquets==m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxDay = *max_element(bloomDay.begin(),bloomDay.end());
        int l=1;
        int r=maxDay;
        int ans=-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(isPossible(mid, bloomDay, m ,k))
            {
                ans = mid;
                r=mid -1;
            }else l = mid+1;
        }
        return ans;
    }
};

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