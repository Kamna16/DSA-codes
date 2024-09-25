#include<bits/stdc++.h>
using namespace std;

// approach 1 :
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int i=0;i<arr1.size();i++)
        {
            int curr = arr1[i];
            while(!st.count(curr) && curr > 0)
            {
                st.insert(curr);
                curr = curr/10;
            }
        }
        int maxi = 0;
        for(int i=0;i<arr2.size();i++)
        {
            int curr = arr2[i];
            while(!st.count(curr) && curr > 0)
            {
                curr = curr/10;
            }
            if(curr>0)
            {
                maxi = max(maxi,static_cast<int>(log10(curr)+1));
            }
        }
        return maxi;
    }
};

// approach 1 using Trie :
struct Node{
    public: 
    Node* children[10];
};

class Solution {
public:
    
    Node* getTrieNode()
    {
        Node* node = new Node();
        for(int i=0;i<10;i++)
        {
            node->children[i] = NULL;
        }
        return node;
    }
    void insert(int num , Node* root)
    {
        Node* crawl = root;
        string str = to_string(num);
        for(char ch : str)
        {
            int index = ch-'0';
            if(!crawl->children[index]){
                crawl->children[index] = getTrieNode();
            }
            crawl = crawl->children[index];
        }
    }
    int search(int num , Node* root)
    {
        Node* crawl = root;
        string str = to_string(num);
        int len =0;
        for(char ch : str)
        {
            int index = ch-'0';
            if(crawl->children[index]){
                len++;
                crawl = crawl->children[index];
            }else break; 
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        Node* root = getTrieNode();
        for(int num : arr1)
        {
            insert(num,root);
        }
        int res =0;
        for(int num : arr2)
        {
            res = max(res, search(num,root));
        }
        return res;
    }
};