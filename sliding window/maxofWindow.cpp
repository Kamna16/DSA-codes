#include<bits/stdc++.h>
using namespace std;

// using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); ++i) {
            // Remove elements out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }

            // Add current element at the back of the deque
            dq.push_back(i);

            // The front of the deque is the maximum element of the current window
            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maxOfSubArray(vector<int>& arr, int k) {
        vector<int> ans;
        queue<int> q;
        int maxi = INT_MIN;
        int i = 0, j = 0;
        while (j < k) {
            if (arr[j] > maxi) {
                maxi = arr[j];
            }
            j++;
        }
        ans.push_back(maxi);
        while (j < arr.size()) {
            if (arr[j] > maxi) {
                maxi = arr[j];
            } else {
                if (arr[i] == maxi) {
                    maxi = INT_MIN;
                    for (int x = i + 1; x <= j; x++) {
                        if (arr[x] > maxi) {
                            maxi = arr[x];
                        }
                    }
                }
            }
            ans.push_back(maxi);
            i++;
            j++;
        }
        return ans;
    }
};
int main(){
    
    return 0;
}