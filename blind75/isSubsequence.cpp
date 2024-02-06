#include<bits/stdc++.h>
using namespace std;

class Solution { //self
public:
    bool isSubsequence(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        int i=0, j=0;
        int calc =0;
        while(j<size2)
        {
            if(s[i] == t[j])
            {
                calc++;
                i++;
                j++;
            }
            else j++;
        }
        if(calc == size1) return true;
        return false;
    }
};

int main(){
    
    return 0;
}