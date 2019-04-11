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
