#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	    vector<string> ans;
	    void solve(int i,string &s, string &curr)
	    {
	        if(i>=s.size())
	        {
	            if(curr == "") return;
	            ans.push_back(curr);
	            return;
	        }
	        curr.push_back(s[i]);
	        solve(i+1,s,curr);
	        curr.pop_back();
	        solve(i+1,s,curr);
	    }
		vector<string> AllPossibleStrings(string s){
		    string curr = "";
		    solve(0,s,curr);
		    sort(begin(ans),end(ans));
		    return ans;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
