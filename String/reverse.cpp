#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWord(string str)
    {
        int i=0;
        int j= str.size()-1;
        while(i<=j)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
        
        return str;
    }
};

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}
