#include<iostream>
using namespace std;
class Solution {
    public:
    pair<int, int> swapNumbers(int a, int b) {
       pair<int,int> swap;
       a = a^b;
       b = a^b;
       a = a^b;
       swap.first = a;
       swap.second = b;

       return swap;
    }
};

int main(){
    
    return 0;
}