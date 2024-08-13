#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> grayString = generate(n);
        vector<int> ans;
        for(auto i:grayString)
        {
            ans.push_back(stoi(i,0,2));
        }
        return ans;
    }
    vector<string> generate(int n)
    {
        // base case
        if(n==1){
            return {"0","1"};
        }
        vector<string> ans;
        vector<string> temp = generate(n-1);
        for(int i=0; i<temp.size();i++)
        {
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1; i>=0;i--)
        {
            ans.push_back("1"+temp[i]);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}