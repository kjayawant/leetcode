vector<int> spiralMatrix(vector <vector <int>> &input_mat) {
	int x = input_mat.size();
	int y = input_mat[0].size();

	int up = 0, down = x - 1, left = 0, right = y - 1;
	int k = 0;
	vector <int> res(x*y);
	while (true) {
		for (int i = left; i <= right; i++) {
			res[k++] = input_mat[up][i];
		}
		up++;
		if (up>down) break;

		for (int j = up; j <= down; j++) {
			res[k++] = input_mat[j][right];
		}
		right--;
		if (right<left) break;
		for (int i = right; i >= left; i--) {
			res[k++] = input_mat[down][i];
		}
		down--;
		if (down<up) break;
		for (int j = down; j >= up; j--) {
			res[k++] = input_mat[j][left];
		}
		left++;
		if (left>right) break;
	}

	return res;
}
int getnthprime() {
	int count = 2;
	int check = 6;
	bool prevprime = true;
	bool nextprime = true;
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);
	while (count<10001) {
		for (int i = 0; primes[i] <= sqrt(check + 1); i++) {
			if ((check - 1) % primes[i] == 0) {
				prevprime = false;
			}
			if (check + 1 % primes[i] == 0) {
				nextprime = false;
			}
			if (!(prevprime || nextprime)) {
				break;
			}
			if (prevprime) {
				primes.push_back(check - 1);
				count++;
			}
			if (nextprime) {
				primes.push_back(check + 1);
				count++;
			}
			prevprime = true;
			nextprime = true;
			check += 6;
		}
	}
	return primes[count - 1];
}