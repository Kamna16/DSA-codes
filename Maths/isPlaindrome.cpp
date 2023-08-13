#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        int lastdigit;
        long int revnum=0;
        while(num>0)
        {
            lastdigit = num% 10;
            num = num/10;
            revnum = (revnum*10) + lastdigit;
        }

        if(x == revnum)
        { 
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    
    return 0;
}