#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
};

int main() {
    Trie trie;

    // Inserting words into the trie
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");
    trie.insert("grape");

    // Searching for words in the trie
    std::cout << "Inserted 4 words" << std::endl;

    // Don't forget to free memory for the trie to avoid memory leaks
    // Here, you need to implement a function to delete the trie nodes
    // and then delete the root node. For simplicity, I'm omitting it here.

    return 0;
}
