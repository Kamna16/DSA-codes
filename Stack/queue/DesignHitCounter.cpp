#include<bits/stdc++.h>
using namespace std;
// timestamp is in monotonically increasing order
class HitCounter {
public:
	queue<int> q;
	HitCounter() {

	}
	// push the timestamp at which the hit occured
	void hit(int timestamp) {
		q.push(timestamp);
	}

	int getHits(int timestamp) {
		while(!q.empty())
		{
			int oldElem = q.front();
			// if (timestamp is)old element is out of range, remove it
			if(oldElem < (timestamp- 300+1) )
			{
				q.pop();
			}
			else break;
		}
	}
};

int main(){
    
    return 0;
}