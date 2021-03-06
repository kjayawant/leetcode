// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream> 
#include<vector>
#include<unordered_set>
#include<map>
#include<algorithm>
#include <sstream>
#include<queue>

using namespace std;

int bestRotation(vector<int>& A) {
	int N = A.size();
	vector<int> bad (N,1);
	for (int i = 0; i < N; ++i) {
		int left = (i - A[i] + 1 + N) % N;
		int right = (i + 1) % N;
		bad[left]--;
		//bad[right]++;
		if (left > right)
			bad[0]--;
	}

	int best = -N;
	int ans = 0, cur = 0;
	for (int i = 0; i < N; ++i) {
		cur += bad[i];
		if (cur > best) {
			best = cur;
			ans = i;
		}
	}
	return ans;
}



int main() {
	vector<int> A = { 2,3,1,4,0 };
	int b= bestRotation(A);

	return 0;
}