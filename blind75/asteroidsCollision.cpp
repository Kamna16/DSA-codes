#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            // collision
            while(ans.size()!=0 && asteroids[i]<0 && ans.back()>0){
                int sum = asteroids[i]+ans.back();

                if(sum<0){
                    ans.pop_back();
                }else if(sum >0){
                    asteroids[i]=0;
                    break;
                }else{
                    ans.pop_back();
                    asteroids[i]=0;
                    break;
                }
            }
            if(asteroids[i] != 0)
            {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};


int main(){
    
    return 0;
}