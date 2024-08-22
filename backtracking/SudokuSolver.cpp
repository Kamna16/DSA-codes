#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    
    // Check if placing num at position (i, j) is safe
    bool isSafe(int i, int j, char num, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == num) return false;  // Check row
            if (board[k][j] == num) return false;  // Check column
            // Check 3x3 subgrid
            if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == num) return false;
        }
        return true;
    }

    // Solve the Sudoku puzzle using backtracking
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {  // Find an empty cell
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(i, j, num, board)) {
                            board[i][j] = num;  // Place the number
                            if (solve(board))   // Recursively solve the rest
                                return true;
                            board[i][j] = '.';  // Backtrack if the solution fails
                        }
                    }
                    return false;  // No number can be placed, so backtrack
                }
            }
        }
        return true;  // Sudoku solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();  // Set class member variable
        solve(board);
    }
};
