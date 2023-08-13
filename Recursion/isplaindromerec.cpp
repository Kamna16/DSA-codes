#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool helper(string s,int i,int j)
    {
        if(i >= j) return true;
        if(s[i] != s[j]) return false;
        return helper(s,i+1,j-1);
    }
	bool isPalindrome(string s) {
        for (char& c : s) {
            c = tolower(c);
        }
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());
        string reversed_s(s.rbegin(), s.rend());

        int i=0;
        int j=s.length()-1;
        return helper(s,i,j);
        }
};
class Solution {
public:
	bool isPalindrome(string s) {
		// Step 1: Convert the string to lowercase
        for (char& c : s) {
            c = tolower(c);
        }

        // Step 2: Remove all non-alphanumeric characters
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());

        // Step 3: Compare the modified string with its reverse
        string reversed_s(s.rbegin(), s.rend());
        return s == reversed_s;
        }
};
int main(){
    
    return 0;
}