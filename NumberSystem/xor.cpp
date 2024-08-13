#include<iostream>
using namespace std;
class Solution {
public:
	int getOddOccurrence(vector<int>& arr) {
		int Xor =0;
		for(int i=0;i<arr.size();i++)
		{
			Xor ^= arr[i];
		}

		return Xor;
	}
};

int main(){
    
    return 0;
}