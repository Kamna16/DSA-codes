#include<iostream>
using namespace std;
class Solution {
public:
	int minCost(int i, int n, vector<int>& cost, int *dp){
		if(i>=n) return 0;
		if(dp[i] != -1) return dp[i];
		int op1 = minCost(i+1,n,cost,dp);
		int op2 = minCost(i+2,n,cost,dp);
		return dp[i] = cost[i] + min(op1,op2);
	}
	int minCostClimbingStairs(vector<int>& cost) {
		int n= cost.size();
		int dp[n+1];
		for(int i=0;i<n;i++) dp[i]=-1;
		return min(minCost(0,n,cost,dp), minCost(1,n,cost,dp));
	}
};

int main(){
    
    return 0;
}