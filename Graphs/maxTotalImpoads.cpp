#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        for(auto edge : roads)
        {
            degree[edge[0]] += 1;
            degree[edge[1]] += 1;
        }
        sort(degree.begin(),degree.end());
        long long num = n;
        long long sum =0;
        for(int i=n-1;i>=0;i--)
        {
            sum += degree[i] * num;
            num--;
        }
        return sum;
    }
};

int main(){
    
    return 0;
}