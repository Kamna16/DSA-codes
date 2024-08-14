#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void merge(int p,int q, int r, vector<int> & arr)
	{
		int n = q-p+1;
		int m = r -q;
		vector<int> arr1(n);
		vector<int> arr2(m);
		int j=0;
		for(int i=p;i<=q;i++)
		{
			arr1[j] = arr[i];
			j++;
		}
		j=0;
		for(int i=q+1;i<=r;i++)
		{
			arr2[j] = arr[i];
			j++;
		}
		int i=0,k=p;
		j=0;
		while(i<n && j<m)
		{
			if(arr1[i] < arr2[j])
			{
				arr[k] = arr1[i];
				k++;
				i++;
			}
			else
			{
				arr[k] = arr2[j];
				k++;
				j++;
			}
		}
		while(i< n)
		{
			arr[k] = arr1[i];
				k++;
				i++;
		}
		while(j<m)
		{
				arr[k] = arr2[j];
				k++;
				j++;
		}
	}
	vector<int> sortArray(vector<int>& arr, int l, int r) {
		if(l>=r) return arr;
		int mid = l + ( r-l) /2;
		sortArray(arr, l, mid);
		sortArray(arr, mid+1, r);
		merge(l,mid,r,arr);
		return arr;
	}
};

int main(){
    
    return 0;
}










