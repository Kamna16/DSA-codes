#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int row = 1;
    while (row<=n)
    {
        int col = 1;
        int start = 'A';
        while (col<=n)
        {
            char ch = 'A'+row-1;
            cout<<ch<<" ";
            col++;
        }
        cout<<endl;
        row++;

    }
    
    return 0;
}