#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s="";
        s.push_back(chars[0]);
        int count=1;
        for(int i=1;i<n;i++)
        {
            char curr = chars[i];
            if(curr == chars[i-1])
            {
                count++;
            }else{
                if(count >1)
                {
                    s += to_string(count);
                }
                count =1;
                s += curr;
            }
        }
        if(count > 1)
        {
            s += to_string(count);
        }
        for(int i=0;i<s.size();i++)
        {
            chars[i] = s[i];
        }
        return s.size();
    }
};

int main(){
    
    return 0;
}