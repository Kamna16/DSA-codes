#include<bits/stdc++.h>
using namespace std;
void pattern21(int n)
{
    for (int i = 0; i < 2*n; i++)
    {
        int col = i;
        if(i >n) col = n-(i-n);
        for (int j = 0; j < col; j++)
        {
            cout<<"* ";
        }cout<<endl;
    }
    
}

int main(){
    pattern21(5);
    return 0;
}