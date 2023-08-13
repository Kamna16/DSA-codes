#include <iostream>
#include <string>
using namespace std;

string convertDecimalToHexadecimal(int decimalNumber) {
    string hexadecimal = "";

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexadecimal = to_string(remainder) + hexadecimal;
        } else {
            char hexDigit = 'A' + remainder - 10;
            hexadecimal = hexDigit + hexadecimal;
        }
        decimalNumber /= 16;
    }

    return hexadecimal;
}

int main() {
    int decimalNumber = 42;
    string hexadecimal = convertDecimalToHexadecimal(decimalNumber);
    cout << "Hexadecimal representation: " << hexadecimal << endl;

    return 0;
}
