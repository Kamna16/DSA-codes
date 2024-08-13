#include<iostream>
using namespace std;
// Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
class Solution {
public:
	int findTheLongestSubstring(string s) {
		// Map to store the last occurrence index of the count of each vowel combination
        unordered_map<int, int> lastOccurrence;
        // Initialize the map with count 0 for all vowels and -1 for an empty substring
        lastOccurrence[0] = -1;

        // Vowel bit mask: a -> 1, e -> 2, i -> 4, o -> 8, u -> 16
        int mask = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == 'a') mask ^= 1;
            else if (c == 'e') mask ^= 2;
            else if (c == 'i') mask ^= 4;
            else if (c == 'o') mask ^= 8;
            else if (c == 'u') mask ^= 16;

            if (lastOccurrence.find(mask) == lastOccurrence.end()) {
                // If the current mask is not in the map, add it with its index
                lastOccurrence[mask] = i;
            } else {
                // If the current mask is already in the map, update maxLength
                maxLength = max(maxLength, i - lastOccurrence[mask]);
            }
        }

        return maxLength;
	}
};
int main(){
    
    return 0;
}