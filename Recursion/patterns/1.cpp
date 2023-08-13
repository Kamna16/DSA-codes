#include<iostream>
using namespace std;
void func(int r, int c)
{
    if(r ==0) return;
    if( r != c)
    {
        func(r, c+1);
        cout<< '*' << " ";
    }
    else{
        func(r-1,0);
        cout<< endl;
    }
}
// void func(int r, int c)
// {
//     if(r ==0) return;
//     if( r != c)
//     {
//         cout<< '*' << " ";
//         func(r, c+1);
//     }
//     else{
//         cout<< endl;
//         func(r-1,0);
//     }
// }

int main(){
    func(4,0);
    return 0;
}