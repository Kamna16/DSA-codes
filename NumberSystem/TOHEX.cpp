#include<iostream>
using namespace std;
class Solution {
public:
	string toHex(int num) {
		if (num == 0) {
            return "0";
        }

        string hexChars = "0123456789abcdef";
        string result = "";

        while (num != 0 && result.length() < 8) {
            int remainder = num & 15; // Get the last 4 bits (equal to num % 16)
            result = hexChars[remainder] + result;
            num >>= 4; // Right shift num by 4 bits (equal to num /= 16)
        }

        return result;
	}
};

int main(){
    
    return 0;
}