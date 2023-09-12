#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int ConvertToBinary(string & word)
	{
		int ans =0;
		for(int i=0;i<word.length();i++)
		{
			char curr_char = word[i];
			int index = curr_char - "'a";
			// set the bit at index
			ans = (ans|1<<index);
		}
		return ans;
	}
	int maxProduct(vector<string>& words) {
		int n = words.size();
		vector<int> binary_representation;
		for(int i=0;i,n;i++)
		{
			string curr_word = words[i];
			int curr_repr = ConvertToBinary(curr_word);
			binary_representation.push_back(curr_repr);
		}
		int ans =0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;<j<n;j++)
			{
				if(binary_representation[i] & binary_representation[j] == 0){
					//this pair is valid
					ans = max(ans,words[i].length() * words[j].length());
				}
			}
		}
	}
};
int main(){
    
    return 0;
}