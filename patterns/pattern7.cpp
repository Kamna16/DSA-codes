#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i;
    while (i<=n)
    {
        int j = 1;
        int value = 1;
        while (j<=i)
        {
            cout<<value<<" ";
            value++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}