#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        int count1 =0, count2=0;
        int elem1= INT_MIN, elem2= INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(count1 ==0 && elem2 != nums[i] )
            {
                count1++;
                elem1 = nums[i];
            }
            else if(count2 ==0 && elem1 != nums[i] )
            {
                count2++;
                elem2 = nums[i];
            }
            else if(nums[i] == elem1) count1++;
            else if(nums[i] == elem2) count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==elem1) count1++;
            if(nums[i]==elem2) count2++;
        }
        int mini = (int)(n/3)+1;
        if(count1 >= mini) ans.push_back(elem1);
        if(count2 >= mini) ans.push_back(elem2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n= nums.size();
        int bound = (n/3)+1;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int bound = n/3;
        for(auto i : mp)
        {
            if(i.second > bound)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}