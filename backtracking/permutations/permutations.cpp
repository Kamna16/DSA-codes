#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations/

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans,vector<int> &temp)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            backtrack(nums,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums,ans,temp);
        return ans;
    }
};;

class Solution {
public:
	void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            generatePermutations(nums, start + 1, result);
            //backtracking
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generatePermutations(nums, 0, result);
        return result;
    }
};

int main(){
    
    return 0;
}