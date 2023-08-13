#include<iostream>
using namespace std;
// binary search
class Solution {
public:
    int mySqrt(int x) {
        long long i=0;
        long long j=x;
        long long ans =0;
        while(i <= j){
           long long mid = i + (j-i)/2;
           if(mid*mid <= x){
               i = mid+1;
               ans = mid;
           }
           else{
               j = mid-1;
           }
        }
        return ans;
    }
};
// linear search
class Solution {
public:
    int mySqrt(int x) {
        long long y=0;

        while(y*y <= x) y++;

        return y-1;
    }
};

int main(){
    
    return 0;
}