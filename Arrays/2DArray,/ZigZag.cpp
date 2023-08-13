#include <iostream>
#include <vector>

using namespace std;

vector<int> zigzagOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int rows = matrix.size();
    if (rows == 0) {
        return result;
    }
    int cols = matrix[0].size();
    int row = 0;
    int col = 0;
    bool moveRight = true;

    while (row < rows) {
        result.push_back(matrix[row][col]);

        if (moveRight) {
            if (col == cols - 1) {
                row++;
                moveRight = false;
            } else {
                col++;
            }
        } else {
            if (col == 0) {
                row++;
                moveRight = true;
            } else {
                col--;
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> traversal = zigzagOrder(matrix);
    cout << "Zigzag Order Matrix Traversal:" << endl;
    for (int element : traversal) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
