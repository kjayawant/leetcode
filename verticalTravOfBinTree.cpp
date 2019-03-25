#include "stdafx.h"
// C++ program for vertical traversal of binary tree
#include<iostream> 
#include<vector>
#include<algorithm>
#include<queue>
#include "ConsoleApplication4.h"

using namespace std;

struct TreeNode {
	TreeNode * left;
	TreeNode * right;
	int data;
	TreeNode(int val) :data(val), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (!root) 
		return res;
	map<int, vector<int>> vertLines;
	queue<pair<int, TreeNode*>> q;
	q.push({ 0, root });
	while (!q.empty()) {
		auto a = q.front();
		q.pop();
		vertLines[a.first].push_back(a.second->data);

		if (a.second->left) {
			q.push({ a.first - 1,a.second->left });
		}
		if (a.second->right) {
			q.push({ a.first + 1,a.second->right });
		}
	}

	for (auto a : vertLines) {
		res.push_back(a.second);
	}

	return res;
}

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	TreeNode *a = new TreeNode(20);
	root->right = a;
	a->left = new TreeNode(15);
	a->right = new TreeNode(7);
	vector < vector<int >> res = verticalOrder(root);

	return 0;
}