#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(6);
    mylist.push_back(3);
    mylist.push_back(9);
    mylist.push_back(7);
    mylist.push_back(4);
    mylist.push_back(5);

    list<int>::iterator it;
    for(it=mylist.begin();it!=mylist.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    mylist.sort();
    mylist.reverse();
    // for(auto it=vec.rbegin();it!=vec.rend();it++)
    // {
    //     cout<<*it<<" ";
    // }
    
    int el = 3;
    auto ite= find(mylist.begin(), mylist.end(),el);
    if(ite!= mylist.end())
    {
        cout<<"found "<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0;
}