// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int i = 1;
//     char ch = 'A';
//     while (i<=n)
//     {
//         int j = 1;
        
//         while (j<=i)
//         {
//             cout<<ch<<" ";
//             j++;
//         }
//         ch++;
//         cout<<endl;
//         i++;
        
//     }
    
//     return 0;
// }
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i = 1;
    while (i<=n)
    {
        int j = 1;
        
        while (j<=i)
        {
             char ch = 'A'+i-1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
        
    }
    
    return 0;
}