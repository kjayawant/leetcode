// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// C++ program to find sum of 4 numbers in an array
#include<iostream> 
#include<list> 
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include "ConsoleApplication4.h"

using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector <int>> results;
	size_t k, l;
	sort(nums.begin(),nums.end());
	for (size_t i = 0; i<nums.size(); i++) {
		for (size_t j = i+1; j<nums.size(); j++) {
			k = j + 1;
			l = nums.size() - 1;
			while (k<l) {

				if (nums[i] + nums[j] + nums[k] + nums[l] < target)
					k++;
				else if (nums[i] + nums[j] + nums[k] + nums[l] > target)
					l--;
				else {
					results.push_back({ nums[i],nums[j],nums[k],nums[l] });
					if (k < l) {
						k++;
					}
					if (l > k) {
						l--;
					}
				}
			}
		}
	}
	return results;
}

int main()
{
	vector<int> b = {-3,-2,-1,0,0,1,2,3};
	vector<vector<int>> a = fourSum(b,0);
	
	cout << endl;
	return 0;
}
