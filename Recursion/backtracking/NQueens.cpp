// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(int r, int c, vector<string> &board)
    {
        // check upwards
        for(int i=r-1;i>=0;i--)
        {
            if(board[i][c] == 'Q') return false;
        }
        // check diagonals
        for(int i=r-1, j=c-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j] == 'Q') return false;
        }
        // check right
        for(int i=r-1,j=c+1;i>=0 && j<board.size();i--,j++)
        {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board,int row)
    {
        if(row >= board.size())
        {
            ans.push_back(board);
            return;
        }
        for(int col=0;col<board.size();col++)
        {
            if(isValid(row,col,board))
            {
                board[row][col] = 'Q';
                solve(board,row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board, 0);
        return ans;
    }
};

class Solution {
public:
    bool isSafe(int row, int col,vector<string> &board, int n )
    {
        // check upper diagonal
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        col = dupcol;
        row = duprow;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = dupcol;
        row = duprow;
        while(row < n && col >=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n;i++)
        {
            board[i] = s;
        }
        // 0 --> column
        solve(0,board,ans,n);
        return ans;

    }
};

int main(){
    
    return 0;
}