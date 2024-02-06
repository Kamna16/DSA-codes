#include<bits/stdc++.h>
using namespace std;

// void subseq(string p, string up)
// {
//     if (up.empty())
//     {
//         cout<<p<<endl;
//         return;
//     }
//     char ch = up[0];

//     subseq(p+ch, up.substr(1));
//     subseq(p, up.substr(1));
    
// }

void printf(vector<int> &ds,int arr[], int n, int i)
{
    if(i >= n)
    {
        for(auto it: ds)
        {
            cout<<it<< " ";
        }cout<<endl;
        return;
    }
    //pick
    ds.push_back(arr[i]);
    printf(ds,arr,n,i+1);

    //not pick
    ds.pop_back();
    printf(ds,arr,n,i+1);
}

int main(){
    // subseq(" ","abc");
    int arr[] = {3,1,2};
    int n=3;
    vector<int> ds;
    printf(ds,arr,n,0);
    return 0;
}