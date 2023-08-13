#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1 || n==2) return true;
        if(n ==0 || n%2 !=0){
            return false;
        }
        return isPowerOfTwo(n/2);
    }
};
bool isPowerOfTwo(int num, int divisor = 2) {
    // Base case: Check if the number is 1, which is 2^0, and hence a power of 2
    if (num == 1) {
        return true;
    }

    // Base case: Check if the number is 0 or not divisible by the current divisor
    if (num == 0 || num % divisor != 0) {
        return false;
    }

    // Recursive case 1: If the number is divisible by the current divisor, reduce the number and make a recursive call
    if (num % divisor == 0) {
        return isPowerOfTwo(num / divisor, divisor);
    }

    // Recursive case 2: If the number is not divisible by the current divisor, update the divisor to the next power of 2 and make a recursive call
    return isPowerOfTwo(num, divisor * 2);
}

int main(){
    
    return 0;
}