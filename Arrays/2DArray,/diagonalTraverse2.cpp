#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto i : mp)
        {
         for(auto num : i.second){
            ans.push_back(num);
         }   
        }
        return ans;
    }
};

int main(){
    
    return 0;
}