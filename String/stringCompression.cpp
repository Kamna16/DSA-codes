#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i =0;
        int idx = 0;
        while(i<n)
        {
            int count =0;
            char currChar = chars[i];
            while(i<n && chars[i] == currChar)
            {
                count++;
                i++;
            }
            chars[idx] = currChar;
            idx++;
            if(count >1)
            {
                string countStr = to_string(count);
                for(auto ch : countStr)
                {
                    chars[idx] = ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};

int main(){
    
    return 0;
}