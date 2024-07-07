#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;
        while(numBottles>=numExchange)
        {
            consumed += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }   
        return consumed+numBottles;
    }
};

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptyBottles = numBottles;
        numBottles =0;
        while(emptyBottles>=numExchange)
        {
            int extraFullBottles = emptyBottles/numExchange;
            int rem = emptyBottles%numExchange;
            consumed += extraFullBottles;
            emptyBottles = rem + extraFullBottles;
        }   
        return consumed;
    }
};

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int extra = 0;
        while(numBottles>=numExchange)
        {
            numBottles -= (numExchange-1);
            extra++;
        }   
        return consumed+extra;
    }
};