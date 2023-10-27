#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	int mini = INT_MAX;
    	int maxi = INT_MIN;
    	for(int i=0;i<N;i++)
    	{
    	    if(A[i] < mini) mini = A[i];
    	    if(A[i] > maxi) maxi = A[i];
    	}
    	
    	return mini + maxi;
    }

};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}