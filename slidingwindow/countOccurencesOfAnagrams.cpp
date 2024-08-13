#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int search(string pat, string txt) {
	   int n = txt.size();
	   int m = pat.size();
	   unordered_map<char,int> mp;
	   for(int i=0;i<m;i++)
	   {
	       mp[pat[i]]++;
	   }
	   int ans=0;
	   int i=0, j=0;
	   while(j<n)
	   {
	       mp[txt[j]]--;
	       
	       if(j-i+1 == m)
	       {
	           bool greater = false;
	           for(auto p : mp)
	           {
	               int count = p.second;
	               if(count >= 1){
	                   greater=true;
	                   break;
	               }
	           }
	           if(!greater) ans++;
	           
	           mp[txt[i]]++;
	           i++;
	       }
	       
	       j++;
	   }
	   
	   return ans;
	}

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
