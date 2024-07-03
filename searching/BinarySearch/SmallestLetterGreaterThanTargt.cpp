#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
            int s =0;
            int e = letters.size()-1;
            while(s<=e)
            {
                int mid = s +(e-s)/2;
                if( target < letters[mid]) 
                {
                    e= mid-1;
                }
                else
                {
                    s= mid+1;
                }
            }
            if(s > letters.size()-1) return letters[0];
            return letters[s];
    }
};

// using stl 
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(letters.begin(),letters.end(),target)-begin(letters);
        return idx == letters.size() ? letters[0] : letters[idx]; 
    }
};