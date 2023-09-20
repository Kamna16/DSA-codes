#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    vector<int> set;
    MyHashSet() {
        set.resize(1000001,0);
    }
    int hashFunction(int n)
    {
        return n%1000001;
    }
    
    void add(int key) {
        int i = hashFunction(key);
        set[i] = 1;
    }
    
    void remove(int key) {
        int i = hashFunction(key);
        set[i] = 0;
    }
    
    bool contains(int key) {
        int i = hashFunction(key); 
        return (set[i]);
    }
};

// using linked list for handling collisions
class MyHashSet {
public:
    vector<list<int>> set;
    MyHashSet() {
        set.resize(1001);
    }
    int hashFunction(int n)
    {
        return n%1001;
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i = hashFunction(key);
        set[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hashFunction(key);
        if(contains(key))
        {
            set[i].erase(find(set[i].begin() , set[i].end() , key));
        }
        
    }
    
    bool contains(int key) {
        int i = hashFunction(key); 
        return (find(set[i].begin() , set[i].end() , key) != set[i].end());
    }
};

int main(){
    
    return 0;
}