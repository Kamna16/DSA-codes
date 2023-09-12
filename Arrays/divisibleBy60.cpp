#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> m;
				map<int,int>:: iterator it;
				int count =0;
				for(int i=0;i<time.size();i++)
				{
					int r= time[i]%60;
					it = m.find(60-r);
					if(it != m.end())
					{
						count += it->second;
					}
					if(r==0)
					{
						it = m.find(0);
						if(it != m.end())
						{
							count += it->second;
						}
					}
					it = m.find(r);
					if(it!= m.end()) it->second++;
					else{
						m.insert({r,1});
					}
					
				}
				return count;
    }
};

int main(){
    
    return 0;
}