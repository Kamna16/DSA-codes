// Given a positive integer n, find the pivot integer x such that:

// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
// Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

#include<iostream>
using namespace std;
int pivotInteger(int n) {
		for (int x = 1; x <= n; x++) {
            int sum1 = (x * (x + 1)) / 2;               
            int sum2 = ((n - x + 1) * (n + x)) / 2;  

            // Check if the sums are equal
            if (sum1 == sum2) {
                return x;   
            }
        }
    return -1;
}
int main(){
    
    return 0;
}