//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}


vector<long long> printFirstNegativeInteger(long long int A[],long long int n, long long int K) {
    vector<long long> ans;
    queue<long long> q;
    int i=0,j=0;
    while(j<n)
    {
        if(A[j] < 0)
        {
            q.push(A[j]);
        }
        if((j-i+1) == K)
            {
                if(q.size() == 0) ans.push_back(0);
                else ans.push_back(q.front());
                if(A[i] < 0) q.pop();
                i++;
            }
            j++;
    }
    return ans;
 }