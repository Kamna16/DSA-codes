#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i= digits.size()-1; i>=0;i--)
        {
            if(digits[i]< 9){
                digits[i] += 1;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits.push_back(0);
        digits[0] =1;
        return digits;
    }
};
class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Start from the rightmost digit
    for (int i = digits.size() - 1; i >= 0; i--) {
        // Increment the current digit by one
        digits[i] += 1;

        // If the current digit is less than 10 (no carry-over needed), we can return the result
        if (digits[i] < 10) {
            return digits;
        }

        // If there is a carry-over, set the current digit to 0
        digits[i] = 0;
    }

    // If we reach this point, it means the entire number was 9s, so we need to add one more digit at the beginning
    digits.insert(digits.begin(), 1);
    return digits;
    }
};

int main(){
    
    return 0;
}