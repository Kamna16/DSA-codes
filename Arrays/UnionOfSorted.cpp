#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector < int > sortedArray(vector < int > a, vector < int > b) {
    
    set<int> st;
    int n1= a.size();
    int n2= b.size();
    for(int i=0;i<n1;i++)
    {
        st.insert(a[i]);
    }
    for(int i=0;i<n2;i++)
    {
        st.insert(b[i]);
    }
    vector<int> uni;
    for(auto it : st)
    {
        uni.push_back(it);
    }
    return uni;

}

int main(){
    
    return 0;
}