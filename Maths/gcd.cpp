#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
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
int hcf(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    int num1 = 24;
    int num2 = 36;
    int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}
