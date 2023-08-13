#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> computeIntersectionUsingHashSet(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set;
    vector<int> intersection;

    for (int num : arr1) {
        set.insert(num);
    }

    for (int num : arr2) {
        if (set.count(num) > 0) {
            intersection.push_back(num);
            set.erase(num); // If duplicates need to be considered, remove this line
        }
    }

    return intersection;
}

vector<int> computeIntersectionUsingSorting(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> intersection;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return intersection;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    vector<int> intersection1 = computeIntersectionUsingHashSet(arr1, arr2);
    cout << "Intersection using hash set: ";
    for (int num : intersection1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> intersection2 = computeIntersectionUsingSorting(arr1, arr2);
    cout << "Intersection using sorting: ";
    for (int num : intersection2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
