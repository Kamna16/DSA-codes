#include<bits/stdc++.h>
using namespace std;

int isPrime(int N){
        if(N == 1) return false;
        int sq = sqrt(N);
        for(int i=2;i<=sq;i++)
        {
            if(N%i == 0) return false;
        }
        return true;
}

int main(){
    
    return 0;
}