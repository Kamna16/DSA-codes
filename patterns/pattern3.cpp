#include<iostream>
using namespace std;

int main(){
    int p;
    cin>>p;

    int i=1;
    int count = 1;
    while (i<=p)
    {
        int j=1;
        while (j<=p)
        {
           cout<<count<<" ";
           count++;
           j++;
        }
        cout<<endl;
        i++;
        
    }
    

    return 0;
}