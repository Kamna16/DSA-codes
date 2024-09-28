#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int dp[1001]; 
    
    int solve(int price[], int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int maxVal = INT_MIN;
        
        for (int i = 1; i <= n; i++) {
            maxVal = max(maxVal, price[i - 1] + solve(price, n - i));
        }
        
        return dp[n] = maxVal;
    }
    
    int cutRod(int price[], int n) {
        memset(dp, -1, sizeof(dp));
        return solve(price, n);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}