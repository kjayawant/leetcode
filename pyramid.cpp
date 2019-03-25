#include "stdafx.h"
// C++ program string to find valid combination of characters forming a pyramid
#include<iostream> 
#include<list> 
#include<vector>
#include<algorithm>
#include "ConsoleApplication4.h"

using namespace std;
bool tripletAllowed(int start, string bottom, vector<string>& allowed, string nextBottom) {
	if (bottom.length() - 1 == nextBottom.length()) {
		if (nextBottom.length() == 1)
			return true;
		else
			return tripletAllowed(0, nextBottom, allowed, "");
	}
	else {
		for (size_t i = 0; i<allowed.size(); i++) {
			if (allowed[i][0] == bottom[start] && allowed[i][1] == bottom[start + 1]) {
				if (tripletAllowed(start + 1, bottom, allowed, nextBottom + allowed[i][2]))
					return true;
			}
		}
		return false;
	}
}
bool pyramidTransition(string bottom, vector<string>& allowed) {
	return (tripletAllowed(0, bottom, allowed, ""));
}

int main()
{
	vector<string> allowed = {"AAA","AAB","ABA","ABB","BAC"};
	
	bool a = pyramidTransition("AABA", allowed);
	
	cout << endl;
	return 0;
}
