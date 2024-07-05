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

class Trie {
public:
    struct trieNode{
        bool isEnd;
        trieNode* children[26];
    };
    trieNode* root;

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for(int i=0;i<26;i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* Node = root;
        for(char ch : word){
            int index = ch-'a';
            if(Node->children[index]==NULL)
            {
                Node->children[index] = getNode();
            }
            Node= Node->children[index];
        }
        Node->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* Node = root;
        for(char ch : word){
            int index = ch-'a';
            if(Node->children[index]==NULL) return false;
            Node= Node->children[index];
        }
        return Node->isEnd;
    }
    
    bool startsWith(string word) {
        trieNode* Node = root;
        for(char ch : word){
            int index = ch-'a';
            if(Node->children[index]==NULL) return false;
            Node= Node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */