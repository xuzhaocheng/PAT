#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

#define N 110001

using namespace std;

vector<bool> prime(N, true);


/*
** 二次探测法hash
** index = (number % table_size + f(i)) % table_size
** 其中f(i) = i * i   0 <= i < table_size
**
** 为什么用筛选法求的质数就是过不了case 2？？？？？
*/
int find_position(vector<bool> &hash_table, int number) {
	int i = 0;
	int table_size = hash_table.size();
	
	while (i < table_size) {
		int index = (number % table_size + i * i) % table_size;
		if (!hash_table[index]) {
			hash_table[index] = true;
			return index;
		}
		i++;
	}

	return -1;
}

bool is_prime(int number) {
	if (number == 1) return false;
	for (int i = 2; i <= sqrt(number); ++i)
		if (number % i == 0) return false;
	return true;
}

int main(void) {
	// freopen("../in/1078.in", "r", stdin);
	int m, n;
	cin >> m >> n;

	// find the smallest prime larger than m
	for (int i = m; i < N; i++) {
		if (is_prime(i)) {
			m = i;
			break;
		}
	}

	int num;
	vector<bool> hash_table(m, false);
	for (int i = 0; i < n; i++) {
		cin >> num;
		int index = find_position(hash_table, num);
		if (index != -1)
			cout << index;
		else cout << "-";
		if (i != n - 1)
			cout << " ";
	}

	return 0;
}