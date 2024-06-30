#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int a, int b)
    {
        int count =0;
        int row =1;
        while(a>0 || b> 0)
        {
            if(row%2 == 1)
            {
                if(a >= row)
                {
                    a -= row;
                }else break;
            }else{
                if(b>=row)
                {
                    b-=row;
                }else break;
            }
            count++;
            row++;
        }
        return count;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red,blue),helper(blue,red));
    }
};