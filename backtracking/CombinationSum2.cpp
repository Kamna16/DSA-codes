#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int>& candidates, int target,int idx,vector<int> &temp)
    {
        if(target <0) return;
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,target, 0,temp);
        return ans;
    }
};

class Solution {
public:
    void recur(vector<int>& candidates,int ind, int target, vector<int> &list,vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(list);
            return;
        }

        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

                //pick
            list.push_back(candidates[i]);
            //not pick
            recur(candidates,i+1,target-candidates[i],list,ans);
            list.pop_back(); // backtrack step
        
        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> list;
        vector<vector<int>> ans;
        recur(candidates,0,target,list,ans);
        return ans;
    }
};

int main(){
    
    return 0;
}