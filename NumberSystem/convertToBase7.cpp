#include<iostream>
using namespace std;
class Solution {
public:
	string convertToBase7(int num) {
		int n = abs(num); // We use the absolute value to handle negative numbers
        int base = 0;
        int power = 1;

        // Convert the number to base 7
        while (n > 0) {
            int rem = n % 7;
            base += rem * power;
            n /= 7;
            power *= 10;
        }

        // If the original number was negative, add a minus sign to the result
        if (num < 0) {
            return "-" + to_string(base);
        } else {
            return to_string(base);
        }

	}
};
int main(){
    
    return 0;
}