#include "stdafx.h"
// C++ program to solve n queens puzzle
#include<iostream> 
#include<vector>
#include<algorithm>
#include "ConsoleApplication4.h"

using namespace std;
bool solveRecurse(int n, int row, vector<string> &board, vector<vector<string>> &res);
bool isSafe(int row, int col, vector<string> board);
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string> board(n, string (n, '.'));
	solveRecurse(n, 0, board, res);
	return res;
}

bool solveRecurse(int n, int row, vector<string> &board, vector<vector<string>> &res) {
	for (int i = 0; i<n; i++) {
		if (isSafe(row, i, board)) {
			board[row][i] = 'Q';
			if (row == n-1) {
				res.push_back(board);
				return true;
			}
			solveRecurse(n, row + 1, board, res);
			board[row][i] = '.';
		}
	}
	return false;
}

bool isSafe(int row, int col, vector<string> board) {
	for (int i = 0; i<row; i++) {
		if (board[i][col] == 'Q') return false;
	}
	for (int i = row, j = col; i>=0 && j>=0; i--, j--) {
		if (board[i][j] == 'Q') return false;
	}
	for (int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
		if (board[i][j] == 'Q') return false;
	}
	return true;
}


int main() {
	vector<vector<string>> res=solveNQueens(4);
	return 0;
}