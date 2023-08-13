#include<bits/stdc++.h>
using namespace std;
int countDistinctWays(int nStairs) {
    if(nStairs ==0) return 1;
    if(nStairs < 0) return 0;

    int ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
    return ans;
}

int main(){
    
    return 0;
}