#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string decodeMessage(string key, string message) {
		unordered_map<char, char> m;
        char y = 'a';
        for (char x : key)
        {
            if (x != ' ' && m.find(x) == m.end())
                m.insert({x, y++});
        }
        
        string ans = "";
        for (char x : message)
        {
            if (x != ' ')
                ans += m[x];
            else
                ans += ' ';
        }
        return ans;
	}
};

int main(){
    
    return 0;
}