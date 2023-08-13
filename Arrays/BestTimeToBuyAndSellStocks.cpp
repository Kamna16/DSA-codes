#include<iostream>
#include<vector>
using namespace std;

int main(){
     int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();
        for(int i=0;i<n;i++)
        {
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;

    }
    return 0;
}