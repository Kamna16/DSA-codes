#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int convertBinaryToDecimal(const string& binary) {
    int decimalNumber = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; i--) {
        int digit = binary[i] - '0';
        decimalNumber += digit * pow(2, power);
        power++;
    }

    return decimalNumber;
}

int main() {
    string binary = "101010";
    int decimalNumber = convertBinaryToDecimal(binary);
    cout << "Decimal representation: " << decimalNumber << endl;

    return 0;
}
