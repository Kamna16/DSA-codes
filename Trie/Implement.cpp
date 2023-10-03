#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	Node* children[26];
	bool isEndOfword = false;
};

class Trie {
public:
	Node* root;
	Trie() {
		root =  new Node();
	}
	void insert(string word) {
		Node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			int index = word[i] -'a';
			if(temp->children[index] == NULL)
			{
				temp->children[index] = new Node();
			}
			temp = temp->children[index];
		}
		temp->isEndOfword = true;
	}

	bool search(string word) {
		Node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			int index = word[i] -'a';
			if(temp->children[index] == NULL)
			{
				return false;
			}
			temp = temp->children[index];
		}
		return temp->isEndOfword;
	}

	bool startsWith(string prefix) {
		Node* temp = root;
		for(int i=0;i<prefix.size();i++)
		{
			int index = prefix[i] -'a';
			if(temp->children[index] == NULL)
			{
				return false;
			}
			temp = temp->children[index];
		}
		return true;
	}
};

int main(){
    
    return 0;
}