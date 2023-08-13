#include <iostream>
#include <string>
using namespace std;

string convertDecimalToOctal(int decimalNumber) {
    string octal = "";

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 8;
        octal = to_string(remainder) + octal;
        decimalNumber /= 8;
    }
    return octal;
}

int main() {
    int decimalNumber = 42;
    string octalNumber = convertDecimalToOctal(decimalNumber);
    cout << "Octal representation: " << octalNumber << endl;

    return 0;
}
