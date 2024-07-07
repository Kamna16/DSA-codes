//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    vector<int> solve(struct Node *root, int target, vector<int> &ans)
    {
        if(root == NULL) return {};
        if(root->data == target) return ans;
        
        ans.push_back(root->data);
        vector<int> left = solve(root->left,target,ans);
        if(left.size() != 0) return left;
        vector<int> right =  solve(root->right,target,ans);
        if(right.size() != 0) return right;
        ans.pop_back();
        return {};
    }
    vector<int> Ancestors(struct Node *root, int target) {
        if(root->data == target) return {};
        vector<int> ans;
        vector<int> a = solve(root,target,ans);
        reverse(a.begin(),a.end());
        return a;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);

        int target;
        cin >> target;
        getchar();

        Node* root = buildTree(s);
        Solution obj;
        vector<int> nodes = obj.Ancestors(root, target);
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
    return 1;
}
