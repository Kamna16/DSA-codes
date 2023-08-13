#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(5);

    vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    sort(vec.begin(), vec.end());
    // for(auto it=vec.rbegin();it!=vec.rend();it++)
    // {
    //     cout<<*it<<" ";
    // }
    
    int el = 3;
    auto ite= find(vec.begin(), vec.end(),el);
    if(ite!= vec.end())
    {
        cout<<"found "<<distance(vec.begin(),ite)<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0;
}