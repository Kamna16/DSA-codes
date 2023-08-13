#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindromeHelper(int x, int& original) {
    if (x == 0) {
        // Base case: When the number becomes 0, we have checked all the digits.
        // If the recursion reached this point, then all the digits are the same.
        return true;
    }

    // Recursively call the function to check the remaining digits.
    bool isPal = isPalindromeHelper(x / 10, original);

    // Compare the current digit with the corresponding digit from the end of the original number.
    if (x % 10 == original % 10) {
        // If the digits match, remove the last digit from the original number (right shift).
        original /= 10;
        return isPal; // Continue with the recursion.
    } else {
        return false; // If any digit doesn't match, the number is not a palindrome.
    }
}
    bool isPalindrome(int x) {
        if (x < 0) return false; // Negative numbers are not palindromes
    if (x < 10) return true; // Single-digit numbers are palindromes

    int original = x; // Keep a copy of the original number for comparison

    // Call the recursive helper function to check if the number is a palindrome.
    return isPalindromeHelper(x, original);
    }
};
int main(){
    
    return 0;
}