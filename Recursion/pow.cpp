#include<iostream>
using namespace std;

class Solution {
public:
    double solve(double x, long n)
    {
        if(n==0) return 1;
        if(n<0) return solve(1/x,-n);
        if(n%2 == 0) return solve(x*x,n/2);
        return x* solve(x*x, (n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x,n);
    }
};
long long Pow(int X, int N)
{
    if (N ==0) return 1;
    long long partial = Pow(X , N-1);
    return (X * partial); 
}
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;

        // Handle negative exponents
        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }

        double halfPower = myPow(x, n / 2);
        if (n % 2 == 0) {
            return halfPower * halfPower;
        } else {
            return halfPower * halfPower * x;
        }
    }
};

// 2^6 --------> 2^3 * 2^3


// The base case is still when n is 0, where it returns 1.0.

// If n is 1, it returns x directly.

// If n is negative, it calculates 1/x and sets n to its absolute value to handle negative exponents.

// It calculates halfPower, which is myPow(x, n / 2). This step ensures that we only need to calculate the power once and reuse it for both even and odd exponents.

// If n is even (n % 2 == 0), it returns the square of halfPower.

// If n is odd, it returns the square of halfPower multiplied by x.