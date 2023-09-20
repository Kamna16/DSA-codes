#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> st;
    int top;
    Solution() {
        st.resize(1001, 0);
        top = -1;
    }
	int topElem()
	{
		return st[top];
	}
	void push(int x)
	{
		st[++top] = x;
	}
	int pop()
	{
		return st[top--];
	}

	int calPoints(vector<string>& operations) {
		int n = operations.size();
		for(int i=0;i<n;i++)
		{
			if(operations[i] == "+")
			{
				int a = topElem();
				pop();
				int b = topElem();
				push(a);
				push(a+b);
			}
			else if(operations[i] == "D")
			{
				int a = topElem();
				push(2*a);
			}
			else if(operations[i] == "C")
			{
				pop();
			}
			else{
				push(stoi(operations[i]));
			}
		}
		int sum =0;
		for(int i=0;i<=top;i++)
		{
			sum+= st[i];
		}
		return sum;
	}
};

int main(){
    
    return 0;
}