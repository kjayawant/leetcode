// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<iostream> 
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include <sstream>
#include<set>
#include "ConsoleApplication4.h"

using namespace std;
void DFS(int i, int j, vector<vector<char>>& grid) {
	if (i >= grid.size() || j >= grid[0].size()) {
		return;
	}
	if (grid[i][j] == '1') {
		grid[i][j] = '0';
		DFS(i + 1, j, grid);
		DFS(i - 1, j, grid);
		DFS(i, j + 1, grid);
		DFS(i, j - 1, grid);
	}
	return;

}
int numIslands(vector<vector<char>>& grid) {
	int islands = 0;
	int i, j;
	for (i = 0; i<grid.size(); i++) {
		for (j = 0; j<grid[0].size(); j++) {
			if (grid[i][j] == 49) {
				islands++;
				DFS(i, j, grid);
			}
		}
	}
	return islands;
}





int main() {
	vector<vector<char>> grid;
	grid.push_back({'1','1','0','0','0' });
	grid.push_back({ '1', '1', '0', '0', '0' });
	grid.push_back({ '0', '0', '1', '0', '0' });
	grid.push_back({ '0', '0', '0', '1', '1' });
	
	int b = numIslands(grid);
	return 0;
}