#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b)
    {
        while(b%a !=0)
        {
            int rem = b%a;
            b=a;
            a=rem;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2+str1)
        {
            int a = str1.size();
            int b = str2.size();
            int gcdNum = gcd(a,b);
            return str1.substr(0,gcdNum);
        }
        else return "";
    }
};

int main(){
    
    return 0;
}