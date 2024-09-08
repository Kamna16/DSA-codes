#include <iostream>
#include <string>

using namespace std;

string convertDecimalToBinary(int decimalNumber) {
    string binary = "";

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;
        binary = to_string(remainder) + binary;
        decimalNumber /= 2;
    }

    return binary;
}

int main() {
    int decimalNumber = 14;
    string binary = convertDecimalToBinary(decimalNumber);
    cout << "Binary representation: " << binary << endl;

    return 0;
}
