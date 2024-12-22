#include<iostream>
using namespace std;
bool isSafe(int board[][4], int row, int col) {
int i, j;
// Check the same column upwards
for (i = 0; i < row; i++) {
if (board[i][col] == 1) {
return false;
}
}
// Check the upper left diagonal
for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
if (board[i][j] == 1) {
return false;
}
}
// Check the upper right diagonal
for (i = row, j = col; i >= 0 && j < 4; i--, j++) {
if (board[i][j] == 1) {
return false;
}
}
return true;
}
bool solveNQueens(int board[][4], int row) {
if (row >= 4) {
return true;
}
for (int col = 0; col < 4; col++) {
if (isSafe(board, row, col)) {
board[row][col] = 1;
if (solveNQueens(board, row + 1)) {
return true;
}
board[row][col] = 0; // Backtrack
}

}
// If no position is safe in this row, return false (triggers backtracking)
return false;
}
int main(){
	int arr[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
	
	if (solveNQueens(arr,0)) {
        cout << "Solution Path:" << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
}

