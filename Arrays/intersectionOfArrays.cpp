#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<bool> added;
        int n1= nums1.size();
        for(int i=0;i<n1;i++)
        {
            for(auto n: nums2)
            {
                if(n == nums1[i] && !added[nums1[i]])
                {
                    ans.push_back(nums1[i]);
                    added[nums1[i]]=true;
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}