#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	Node* children[26];
	int isEndOfword = 0;
	int PrefixCount =0;
};
class Trie {
public:
	Node* root;
	Trie() {
		root = new Node();
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
			temp->PrefixCount++;
		}
		temp->isEndOfword++;
	}

	int countWordsEqualTo(string word) {
		Node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			int index = word[i] -'a';
			if(temp->children[index] == NULL)
			{
				return 0;
			}
			temp = temp->children[index];
		}
		return temp->isEndOfword;
	}

	int countWordsStartingWith(string word) {
		Node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			int index = word[i] -'a';
			if(temp->children[index] == NULL)
			{
				return 0;
			}
			temp = temp->children[index];
		}
		return temp->PrefixCount;
	}

	void erase(string word) {
		Node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			int index = word[i] -'a';
			if(temp->children[index] == NULL)
			{
				return;
			}
			temp = temp->children[index];
		}
		temp->isEndOfword--;
	}
};

int main(){
    
    return 0;
}