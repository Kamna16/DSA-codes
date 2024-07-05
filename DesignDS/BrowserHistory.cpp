#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node* back;
    Node() : data(0), next(nullptr), back(nullptr){};
    Node(string x) : data(x), next(nullptr), back(nullptr){};
    Node(string x, Node* next, Node *random) : data(x), next(next), back(random){};
};
class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node *newNode = new Node(url);
        current->next = newNode;
        newNode->back = current;
        current = current->next;
    }
    
    string back(int steps) {
        while(steps)
        {
            if(current->back)
            {
            current = current->back;
            }
            else break;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while(steps>0)
        {
            if(current->next)
            {
                current = current->next;
            }
            else break;
            steps--;
        }
        return current->data;
    }
};


// using stack
class BrowserHistory {
public:
    stack<string> backStack;
    stack<string> forwardStack;
    string curr;
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        backStack.push(curr);
        curr = url;
        forwardStack = stack<string>();
    }
    
    string back(int steps) {
        while(steps>0 && !backStack.empty())
        {
            forwardStack.push(curr);
            curr = backStack.top();
            backStack.pop();
            steps--;
        }
        return curr;
    }
    
    string forward(int steps) {
        while(steps>0 && !forwardStack.empty())
        {
            backStack.push(curr);
            curr = forwardStack.top();
            forwardStack.pop();
            steps--;
        }
        return curr;
    }
};