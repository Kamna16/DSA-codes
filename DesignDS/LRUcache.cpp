#include<bits/stdc++.h>
using namespace std;

//brute force
class LRUCache {
public:
    vector<pair<int,int>> cache;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        for(int i=0;i<n;i++)
        {
            if(cache[i].first == key){
                pair<int,int>temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);// recently used
                return cache[i].first;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        //already present
        for(int i=0;i<n;i++)
        {
            if(cache[i].first == key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value}); // recently used
                return;
            }
        }
        // if capacity reached
        if(cache.size()==n){
            cache.erase(cache.begin());
            cache.push_back({key,value});
        }else cache.push_back({key,value});

    }
};

// optimal
class LRUCache {
public:
    list<int> dll;
    map<int,pair<list<int>::iterator,int>> mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);

        dll.push_front(key);// make recently used

        mp[key].first = dll.begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second =value;
            makeRecentlyUsed(key);
            return;
        }
        dll.push_front(key);
        mp[key] = {dll.begin(),value};
        n--;
        if(n<0)
        {
            int deleteKey = dll.back();
            mp.erase(deleteKey);
            dll.pop_back();
            n++;
        }
    }
};
