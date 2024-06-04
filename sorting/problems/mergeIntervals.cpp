#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!ans.empty() && end <= ans.back()[1])
            {
                continue;
            }
            for(int j=i+1;j<intervals.size();j++)
            {
                if(intervals[j][0] <= end){
                    end = max(end,intervals[j][1]);
                }else break;
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};


int main(){
    
    return 0;
}