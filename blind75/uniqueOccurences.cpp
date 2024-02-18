#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ;
        for (int num : arr) {
            occ[num]++;
        }
        
        set<int> s;
        for (auto& pair : occ) {
            if (!s.insert(pair.second).second) {
                return false; 
            }
        }
        
        return true; 
    }
};

int main(){
    
    return 0;
}