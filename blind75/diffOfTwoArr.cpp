#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int,int> set1;
        for(int i = 0; i < nums1.size(); i++) {
            set1[nums1[i]] = i; // Store the value and its index
        }
        
        unordered_map<int,int> set2;
        for(int i = 0; i < nums2.size(); i++) {
            set2[nums2[i]] = i; // Store the value and its index
        }
        
        vector<int> ans1, ans2;
        for(auto& pair : set1) {
            if(set2.find(pair.first) == set2.end()) {
                ans1.push_back(pair.first);
            }
        }
        
        for(auto& pair : set2) {
            if(set1.find(pair.first) == set1.end()) {
                ans2.push_back(pair.first);
            }
        }
        
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};

int main(){
    
    return 0;
}