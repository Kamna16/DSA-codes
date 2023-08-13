#include<iostream>
using namespace std;
void subseq(string p, string up)
{
    if (up.empty())
    {
        cout<<p<<endl;
        return;
    }
    char ch = up[0];

    subseq(p+ch, up.substr(1));
    subseq(p, up.substr(1));
    
}

int main(){
    subseq(" ","abc");
    return 0;
}