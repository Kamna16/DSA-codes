#include<iostream>
using namespace std;

int main(){
    int p;
    cin>>p;

    int i=1;
    while (i<=p)
    {
        int j=1;
        while (j<=p)
        {
           cout<<j<<" "; 
           j++;
        }
        cout<<endl;
        i++;
        
    }
    

    return 0;
}

/*
  for printing:
  3 2 1
  3 2 1
  3 2 1

int main(){
    int p;
    cin>>p;

    int i=1;
    while (i<=p)
    {
        int j=1;
        while (j<=p)
        {
           cout<<n-j+1<<" "; 
           j++;
        }
        cout<<endl;
        i++;
        
    }
    

    return 0;
}*/