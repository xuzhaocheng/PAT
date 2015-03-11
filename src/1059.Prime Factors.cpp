/*
** 筛选法内存超限
** 分解因数，如果是合数继续分解，直到分到质数为止
** 注意0和1两个特别情况
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

void calcFactors(int n, unordered_map<int, int> &res) {
	bool isPirme = true;
	int m = n;
	int i = 2;

	while (i <= sqrt(m) && m != 2) {
		if (m % i == 0) {
			calcFactors(i, res);
			isPirme = false;
			m = m / i;
			i = 2;
		} else {
			i++;
		}
	}

	if (m != 1) {
		res[m]++;
	}
}

int main(void) {
	// freopen("../in/1059.in", "r", stdin);
	
	int n = 97532468;
	cin >> n;

	if (n <= 3) {
		printf("%d=%d\n", n, n);
		return 0;
	}

	unordered_map<int, int> res;
	calcFactors(n, res);
	unordered_map<int, int>::iterator it;
	vector<int> primes;

	for (it = res.begin(); it != res.end(); it++)
		primes.push_back(it->first);

	std::sort(primes.begin(), primes.end());

	cout << n << "=";
	for (int i = 0; i < primes.size(); i++) {
		if (i != 0) cout << "*";
		cout << primes[i];
		if (res[primes[i]] > 1)
			cout << "^" << res[primes[i]];
	}

	return 0;
}