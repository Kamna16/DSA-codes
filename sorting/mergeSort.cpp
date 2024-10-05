#include<bits/stdc++.h>
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
void merge(int arr[], int l, int m, int h)
{
	int n1 = m-l+1;
	int n2 = h-m;
	int arr1[n1];
	int arr2[n2];
	for(int i=l;i<=m;i++)
	{
		arr1[i] = arr[i];
	}
	for(int i=m+1;i<=h;i++)
	{
		arr1[i] = arr[i];
	}
	int i=0, j=0; 
	int k=0;
	while(i< n1 && j<n2)
	{
		if(arr1[i] <= arr2[j])
		{
			arr[k] = arr[i];
			i++;
		}else if(arr1[i] > arr2[j]){
			arr[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k] = arr[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k] = arr[j];
		j++;
		k++;
	}
}

void mergerSort(int arr[], int l, int h)
{
	int mid = l+h/2;
	mergerSort(arr,l,mid);
	mergerSort(arr,mid+1,h);
	merge(arr,l,mid,h);
}
// -------------------------------------------------------------------------------------
int main(){
	int arr[] = {3,6,4,9,2,5,10,1};

	mergerSort(arr,0,8);
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}