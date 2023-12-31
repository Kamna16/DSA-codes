#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {}; // Handle empty matrix
        int n = matrix[0].size();
        if (n == 0) return {}; // Handle empty rows
         vector<int> ans;
         int top=0, left=0, right=n-1, bottom=m-1;
         while(left <= right && top <= bottom){

            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }top++;

            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }right--;

            if (top <= bottom) { // Check to avoid duplicate row traversal
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) { // Check to avoid duplicate column traversal
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
         }
         return ans;
        
    }
};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.size() == 0) {
        return result;
    }

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    int direction = 0;

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
        } else if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
        } else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        } else if (direction == 3) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> traversal = spiralOrder(matrix);
    cout << "Spiral Matrix Traversal:" << endl;
    for (int num : traversal) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
