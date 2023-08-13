#include <iostream>
using namespace std;

int calculateHCF(int a, int b) {
    if (b == 0)
        return a;
    return calculateHCF(b, a % b);
}

int calculateLCM(int a, int b) {
    int hcf = calculateHCF(a, b);
    return (a * b) / hcf;
}

int main() {
    int num1 = 12;
    int num2 = 18;
    int hcf = calculateHCF(num1, num2);
    int lcm = calculateLCM(num1, num2);

    cout << "HCF of " << num1 << " and " << num2 << " is: " << hcf << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;

    return 0;
}
