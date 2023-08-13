#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int convertOctalToDecimal(string octal) {
    int decimalNumber = 0;
    int power = 0;

    for (int i = octal.length() - 1; i >= 0; i--) {
        int digit = octal[i] - '0';
        decimalNumber += digit * pow(8, power);
        power++;
    }
    
    return decimalNumber;
}

int main() {
    string octal = "52";
    int decimalNumber = convertOctalToDecimal(octal);
    cout << "Decimal representation: " << decimalNumber << endl;

    return 0;
}
