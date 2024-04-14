#include<bits/stdc++.h>
using namespace std;
// brute
#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
   int n = nums.size();
   set<vector<int>> st;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           set<long long> hashset;
           for(int k=j+1;k<n;k++)
           {
               long long sum = nums[i]+nums[j];
               sum+= nums[k];
               long long fourth = target - (sum);
               if(hashset.find(fourth) != hashset.end())
               {
                 vector<int> temp = {nums[i], nums[j], nums[k], int(fourth)};
                 sort(temp.begin(), temp.end());
                 st.insert(temp);
               }
               hashset.insert(nums[k]);
           }
       }
   }
   vector<vector<int>> ans(st.begin(),st.end());
   return ans;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;

    }
};

int main(){
    
    return 0;
}