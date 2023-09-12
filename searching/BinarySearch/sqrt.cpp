#include<bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    int s=1;
    int e=n;

    while(s<=e)
    {
        long long mid = s+(e-s)/2;
        if(mid * mid <= n)
        {
            s = mid+1;
        }
        else e = mid-1;
    }

    return e;
}


int main(){
    
    return 0;
}