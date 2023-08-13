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
            char ch = 'A'+col-1;
            cout<<ch<<" ";
            col++;
        }
        cout<<endl;
        row++;

    }
    
    return 0;
}
// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int row = 1;
//     while (row<=n)
//     {
//         int col = 1;
//         char start = 'A';
//         while (col<=n)
//         {
//             cout<<start<<" ";
//             start++;
//             col++;
//         }
//         cout<<endl;
//         row++;

//     }
    
//     return 0;
// }