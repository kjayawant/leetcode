#include "stdafx.h"
// C++ program to find maximum points from a given set that are on the same line
#include<iostream> 
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include <sstream>
#include<queue>
#include "ConsoleApplication4.h"

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	
};

int maxPoints(vector<Point>& points) {
	unordered_map<float, int> map;

	float x; int cur = 0;
	for (size_t i = 0; i<points.size(); i++) {
		for (size_t j = i + 1; j<points.size(); j++) {
			if (points[i].x - points[j].x == 0)

				x = (float)INT_MAX;
			else
				x = ((float)points[i].y - (float)points[j].y) / ((float)points[i].x - (float)points[j].x);

			if (map.find(x) == map.end() || cur==1) {
				map[x]++;
				cur = 1;
			}
		}
		cur = 0;
	}
	int maxN = 0;
	for (auto k : map) {
		maxN = max(maxN, k.second);
	}
	return maxN+1;
}



int main() {
	vector<Point> A = { Point(0,0), Point(1,1), Point(0,0) };
	int b= maxPoints(A);

	return 0;
}