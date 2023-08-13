#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, int> frequencyMap;
    vector<int> duplicates;

    for (int num : nums) {
        if (frequencyMap.count(num)) {
            duplicates.push_back(num);
        } else {
            frequencyMap[num] = 1;
        }
    }
    return duplicates;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 2, 4, 6, 7, 8, 5};
    vector<int> duplicates = findDuplicates(nums);
    cout << "Duplicate Elements: ";
    for (int i = 0; i < duplicates.size(); i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;
    return 0;
}
