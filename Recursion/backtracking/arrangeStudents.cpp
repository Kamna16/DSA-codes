#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(const vector<char>& seats, int index, int i) {
    if (seats[index] == 'G') {
        if (i + 1 < seats.size() && seats[i + 1] == 'G') {
            return false;
        }
        if (i - 1 >= 0 && seats[i - 1] == 'G') {
            return false;
        }
    }

    if (seats[i] == 'G') {
        if (index + 1 < seats.size() && seats[index + 1] == 'G') {
            return false;
        }
        if (index - 1 >= 0 && seats[index - 1] == 'G') {
            return false;
        }
    }

    return true;
}

void backtrack(vector<string>& arrangements, vector<char>& seats, int index) {
    if (index == seats.size()) {
        string arrangement(seats.begin(), seats.end());
        arrangements.push_back(arrangement);
        return;
    }

    for (int i = index; i < seats.size(); i++) {
        if (isValid(seats, index, i)) {
            swap(seats[index], seats[i]);
            backtrack(arrangements, seats, index + 1);
            swap(seats[index], seats[i]); // backtrack by restoring the original state
        }
    }
}

vector<string> findSeatingArrangements(int numBoys, int numGirls) {
    vector<string> arrangements;
    vector<char> seats(numBoys + numGirls, 'B');
    for (int i = numBoys; i < numBoys + numGirls; i++) {
        seats[i] = 'G';
    }
    backtrack(arrangements, seats, 0);
    return arrangements;
}



int main() {
    int numBoys = 2;
    int numGirls = 2;
    vector<string> arrangements = findSeatingArrangements(numBoys, numGirls);
    for (const string& arrangement : arrangements) {
        cout << arrangement << endl;
    }
    return 0;
}
