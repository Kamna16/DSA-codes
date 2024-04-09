#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            int radiantIndex = radiant.front();
            int direIndex = dire.front();
            radiant.pop();
            dire.pop();
            if (radiantIndex < direIndex) radiant.push(radiantIndex + n);
            else dire.push(direIndex + n);
        }
        
        return radiant.size() > dire.size() ? "Radiant" : "Dire";
    }
};

int main()
{
    return 0;
}