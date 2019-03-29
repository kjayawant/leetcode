// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// C++ program to find minimum gates required at an airport
#include<iostream> 
#include<vector>
#include<map>
#include<queue>
#include<functional>
#include "ConsoleApplication4.h"


using namespace std;

int findMinGates(vector<int> arrivals, vector<int> departures, int flights) {

	priority_queue<int, vector<int>, greater<int>> flightQ;
	flightQ.push(departures[0]);
	int gates = 1;
	for (int i = 1; i<arrivals.size(); i++) {
		if(!flightQ.empty() && flightQ.top()>arrivals[i])
			gates++;

		while (!flightQ.empty() && arrivals[i] > flightQ.top()) {
			flightQ.pop();

		}
		
			
		flightQ.push(departures[i]);

	}
	return gates;
}


int main() {
	vector<int> c = { 200, 210, 310, 320, 350, 500 };
	vector<int> d = { 230, 305, 320, 430, 400, 520 };
	
	int b = findMinGates(c,d,2);

	return 0;
}
