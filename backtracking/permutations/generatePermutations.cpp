#include<bits/stdc++.h>
using namespace std;
//array
class Solution {
public:
    void solve(int i, vector<int> &arr,vector<vector<int>> &ans){
        if(i >= arr.size())
        {
            ans.push_back(arr);
        }
        for(int j=i;j<arr.size();j++)
        {
            swap(arr[i],arr[j]);
            solve(i+1,arr,ans);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};

// string
void generate(int pos, string &str,vector<string> &ans)
{
    if(pos >= str.length())
    {
        ans.push_back(str);
    }

    for(int i=pos;i<str.length();i++)
    {
        swap(str[i],str[pos]);
        generate(pos+1,str,ans);
        swap(str[i],str[pos]);// backtracking
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    generate(0,str,ans);
    sort(ans.begin(),ans.end());
    return ans;
}


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