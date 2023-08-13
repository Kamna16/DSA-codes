#include <iostream>
using namespace std;

const int rows = 3;
const int columns = 3;

void topToLeftBottomRightTraversal(int matrix[rows][columns]) {
    // Traverse the upper half diagonals
    for (int diagonal = 0; diagonal < rows; diagonal++) {
        for (int i = 0, j = diagonal; i <= diagonal; i++, j--) {
            cout << matrix[i][j] << " ";
        }
    }

    // Traverse the lower half diagonals
    for (int diagonal = rows - 1; diagonal >= 1; diagonal--) {
        for (int i = diagonal, j = columns - 1; i < rows; i++, j--) {
            cout << matrix[i][j] << " ";
        }
    }

    cout << endl;
}

void topToRightBottomLeftTraversal(int matrix[rows][columns]) {
    // Traverse the upper half diagonals
    for (int diagonal = 0; diagonal < rows; diagonal++) {
        for (int i = 0, j = columns - 1 - diagonal; i <= diagonal; i++, j++) {
            cout << matrix[i][j] << " ";
        }
    }

    // Traverse the lower half diagonals
    for (int diagonal = 1; diagonal < columns; diagonal++) {
        for (int i = diagonal, j = 0; i < rows; i++, j++) {
            cout << matrix[i][j] << " ";
        }
    }

    cout << endl;
}

int main() {
    int matrix[rows][columns] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Top-Left to Bottom-Right Diagonal Traversal:" << endl;
    topToLeftBottomRightTraversal(matrix);

    cout << "Top-Right to Bottom-Left Diagonal Traversal:" << endl;
    topToRightBottomLeftTraversal(matrix);

    return 0;
}
