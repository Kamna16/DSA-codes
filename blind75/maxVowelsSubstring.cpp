#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<char> vowels = {'a','e','i','o','u'};
        vector<char>::iterator it;
        int count = 0;
        int ans = 0;
        
        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            char cur = s[i];
            it = find(vowels.begin(), vowels.end(), cur);
            if (it != vowels.end()) count++;
        }
        
        ans = count; // Initialize ans
        
        // Slide the window
        for (int i = k; i < s.size(); i++) {
            char cur = s[i];
            it = find(vowels.begin(), vowels.end(), cur);
            if (it != vowels.end()) count++; // Increment count if current character is a vowel
            char prev = s[i - k]; // Previous character going out of the window
            it = find(vowels.begin(), vowels.end(), prev);
            if (it != vowels.end()) count--; // Decrement count if previous character was a vowel
            ans = max(ans, count); // Update ans
        }
        
        return ans;
    }
};

int main(){
    
    return 0;
}