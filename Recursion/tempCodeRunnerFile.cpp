#include<iostream>
using namespace std;

void func(int n)
{
    if(n == 0)
    {
        return;
    }
    cout<<n;
    func(n-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n;
    cin>>n;
    func(n);
    return 0;
}