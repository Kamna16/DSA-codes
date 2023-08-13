#include <iostream>
#include <algorithm>
#include <vector>

void dutchNationalFlagSort(std::vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            std::swap(arr[mid], arr[low]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else if (arr[mid] == 2) {
            std::swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    std::vector<int> arr = {2, 0, 1, 2, 1, 0, 2, 1};
    dutchNationalFlagSort(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
