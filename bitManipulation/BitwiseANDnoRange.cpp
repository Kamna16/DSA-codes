#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left != right)
        {
            left >>= 1;
            right >>= 1;
            count+=1;
        }
        right <<= count;
        return right;
        
    }
};


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left)
        {
            right = right&(right-1);
        }
        return right;
    }
};