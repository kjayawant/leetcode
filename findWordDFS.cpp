#include "stdafx.h"
// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<iostream> 
#include<list> 
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include "ConsoleApplication4.h"

using namespace std;

bool dfs(size_t row, size_t col, int iLetter, string word, vector<vector<char>>& board, vector<vector<bool>>&visited) {
	if (iLetter == word.size())
		return true;
	if (row >= 0 && col >= 0 && row<board.size() && col<board[0].size() && !visited[row][col]) {
		if (board[row][col] == word[iLetter]) {
			visited[row][col] = true;
			cout << board[row][col];
			return (dfs(row + 1, col, iLetter + 1, word, board, visited) || dfs(row - 1, col, iLetter + 1, word, board, visited) || dfs(row, col + 1, iLetter + 1, word, board, visited) || dfs(row, col - 1, iLetter + 1, word, board, visited));
		}
	}
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	size_t i, j;
	bool isExist;
	
	for (i = 0; i<board.size(); i++) {
		for (j = 0; j<board[0].size(); j++) {
			vector<bool> col(board[0].size(), false);
			vector<vector <bool>> visited(board.size(), col);
			if (word[0] == board[i][j])
			{
				if (dfs(i, j, 0, word, board, visited)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> arr = { {'A', 'A'} };
	
	bool a = exist(arr,"AA");
	
	cout << endl;
	return 0;
}
