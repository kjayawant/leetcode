// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// C++ program to find a pair of words that appears the most number of times
#include<iostream> 
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <sstream>  
#include "ConsoleApplication4.h"

using namespace std;
int wordPair(string &paragraph) {

	int count = 0;
	unordered_map <string, int> wordP;
	string token;
	stringstream abc(paragraph);
	vector<string> words;
	while (getline(abc, token, ' ')) {
		words.push_back(token);
	}

	for (size_t i = 0; i < words.size()-1; i++) {
		wordP[words[i] + " " + words[i + 1]]++;
	}

	for (auto j:wordP) {
		count = max(count, j.second);
	}
	return count;
}

int main()
{
	string b = "We traverse through all end of characters. If current character is space, we have reached end of a word, we print current word and reset it to empty. Else we append current end of character to word.";
	int a = wordPair(b);
	
	cout << endl;
	return 0;
}
