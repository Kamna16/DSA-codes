#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter";
    cin>>n;
    for(int i=0;i<n;i++)
	{
		// printing spaces
		for(int j=1;j<=n-i-1;j++)
		{
			cout<<" ";
		}
		// printing stars
		for(int j=1;j<=2*i+1;j++)
		{
			cout<<"*";
		}
		// printing spaces
		for(int j=1;j<=n-i-1;j++)
		{
			cout<<" ";
		}
        cout<<endl;
	}
    return 0;
}