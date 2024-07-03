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

// intersection of arrays 2 

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq2;
        for(int i=0;i<nums2.size();i++)
        {
            freq2[nums2[i]]++;
        }
        vector<int> ans;
        for(int &i: nums1)
        {
            if(freq2[i] > 0)
            {
                ans.push_back(i);
                freq2[i]--;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       int i=0, j=0;
       vector<int> ans;
       while(i<nums1.size() && j<nums2.size())
       {
            if(nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] < nums2[j]){
                i++;
            }else j++;
       }
       return ans;
    }
};