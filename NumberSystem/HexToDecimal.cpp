#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int convertHexadecimalToDecimal(string hexadecimal) {
    int decimalNumber = 0;
    int power = 0;

    for (int i = hexadecimal.length() - 1; i >= 0; i--) {
        char hexDigit = hexadecimal[i];
        int digit;
        if (hexDigit >= '0' && hexDigit <= '9') {
            digit = hexDigit - '0';
        } else {
            digit = hexDigit - 'A' + 10;
        }
        decimalNumber += digit * pow(16, power);
        power++;
    }

    return decimalNumber;
}

int main() {
    string hexadecimal = "2A";
    int decimalNumber = convertHexadecimalToDecimal(hexadecimal);

    cout << "Decimal representation: " << decimalNumber << endl;

    return 0;
}
