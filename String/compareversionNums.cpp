#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getTokens(string v)
    {
        vector<string> tokens;
        stringstream ss(v);
        string token="";
        while(getline(ss,token,'.'))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string> t1 = getTokens(version1);
        vector<string> t2 = getTokens(version2);

        int i=0;
        while(i<t1.size() || i<t2.size())
        {
            int a = i<t1.size()? stoi(t1[i]) :0;
            int b = i<t2.size()? stoi(t2[i]) :0;
            if(a<b) return -1;
            else if(a>b) return 1;
            else i++;
        }
        return 0;
    }
};