#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<long long int, int> mp;
        long long int ans = 0;
        long long int prefixSum =0;
        for(int i=0;i<n;i++)
        {
            prefixSum += arr[i];
            if (prefixSum == 0) {
                ans++;
            }

            if(mp.find(prefixSum) != mp.end())
            {
                ans += mp[prefixSum];
            }
            mp[prefixSum]++;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends

int main(){
    
    return 0;
}