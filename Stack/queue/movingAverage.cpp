#include<bits/stdc++.h>
using namespace std;
class MovingAverage {
public:
	queue<int> q;
	double sum =0;
	int totalNUmOfElem;
	MovingAverage(int size) {
		sum = 0.0;
		totalNUmOfElem = size;
	}

	double next(int val) {
		q.push(val);
		sum += val;
		if(q.size()> totalNUmOfElem)
		{
			int topElem = q.front();
			sum -= topElem;
			q.pop();
		}
		double average = sum/(int)q.size();
		return average;
	}
};

int main(){
    
    return 0;
}