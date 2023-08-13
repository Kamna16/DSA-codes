#include<iostream>
using namespace std;

// void func(int n)
// {
//     if(n == 0)
//     {
//         return;
//     }
//     func(n-1);
//     cout<<n<<endl;
// }
// void func(int n)
// {
//     if(n == 0)
//     {
//         return;
//     }
//     cout<<n<<endl;
//     func(n-1);
// }

// int func(int n)
// {
//     if(n<=1 )
//     {
//         return 1;
//     }
//      return n * func(n-1);
// }

// int func(int n)
// {
//     if(n == 1 )
//     {
//         return 1;
//     }
//     return n + func(n-1);
// }

// void func(int n)
// {
//     if(n == 0)
//     {
//         return;
//     }
//     cout<<n<<endl;
//     func(n-1);
// }
// int func(int n)
// {
//     if(n == 1 )
//     {
//         return 1;
//     }
//     return n + func(n-1);
// }

// int sum(int n)
// {
//     if( n==0) return 0;
//     return (n%10) + sum(n/10);
// }

int reverse(int n)
{
    if( n==0) return 0;
    return (n%10) + reverse(n/10);
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n;
    cin>>n;
    // cout<<func(n);
    return 0;
}