#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end())
        {
            v.push_back(val);
            mp[val] = v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int idx = mp[val];// access the index which we have to remove;
        int lastElement = v.back();
        v.back() = val;

        v[idx] = lastElement;
        mp[lastElement] = idx;

        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int randomIdx = rand()%n;
        return v[randomIdx];
    }
};
