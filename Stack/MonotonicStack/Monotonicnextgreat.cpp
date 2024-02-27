#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class MonotonicStack {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, -1);

        std::stack<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && nums[i] > nums[stack.top()]) {
                result[stack.top()] = nums[i];
                stack.pop();
            }
            stack.push(i);
        }

        return result;
    }
};

int main() {
    MonotonicStack monotonicStack;

    std::vector<int> nums = {3, 1, 4, 2, 5};
    std::vector<int> result = monotonicStack.nextGreaterElement(nums);

    std::cout << "Input: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Next Greater Elements: ";
    for (int res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}

