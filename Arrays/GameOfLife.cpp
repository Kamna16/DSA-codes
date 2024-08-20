#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int n,m;
    int noOfLiveNeighbours(int i, int j, vector<vector<int>>& board) {
        int live = 0;
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                if (x == 0 && y == 0) continue; // Skip the cell itself
                int ni = i + x, nj = j + y;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    // Consider the state of the cell before any changes
                    if (board[ni][nj] == 1 || board[ni][nj] == -1) live++;
                }
            }
        }
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveNeighbours = noOfLiveNeighbours(i, j, board);
                
                if (board[i][j] == 1) {
                    if (liveNeighbours < 2 || liveNeighbours > 3) {
                        board[i][j] = -1; // Mark as live to dead
                    }
                } else {
                    if (liveNeighbours == 3) {
                        board[i][j] = 2; // Mark as dead to live
                    }
                }
            }
        }
        
        // Update the board to the final state
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -1) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};