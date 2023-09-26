#include<bits/stdc++.h>
using namespace std;
//  Method 1
class MyStack {
public:
	queue<int> st;
	MyStack() {

	}

	void push(int x) {
		int size = st.size();
		st.push(x);
		while(size >= 1)
		{
			int front = st.front();
			st.pop();
			st.push(front);
			size--;
		}
	}

	int pop() {
		int topElem = st.front();
		st.pop();
		return topElem;
	}

	int top() {
		return st.front();
	}

	bool empty() {
		if(st.size() <= 0) return true;
		return false;
	}
};

int main(){
    
    return 0;
}