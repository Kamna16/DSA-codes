#include<bits/stdc++.h>
using namespace std;
string read(int n, vector<int> book, int target)
{
    map<int,int> mp;
    for(int i=0;i<book.size();i++)
    {
        int curr = book[i];
        int more = target - book[i];
        if(mp.find(more) != mp.end())
        {
            return "YES";
        }
        mp[curr] = i;
    }
    return "NO";
}
#include<bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    sort(book.begin(), book.end());
        int l=0, r = book.size()-1;
        while(l<=r)
        {
            if((book[l]+book[r]) > target)
            {
                r--;
                
            }
            else if((book[l]+book[r]) < target)
            {
                l++;
            }
            else
            {
               return "YES";
            }
        }
        return "NO";
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
    for(int i=0;i<nums.size();i++)
    {
        int curr = nums[i];
        int more = target - nums[i];
        if(mp.find(more) != mp.end())
        {
            return {mp[more], i};
        }
        mp[curr] = i;
    }
    return {-1,-1};
    }
};

int main(){
    
    return 0;
}