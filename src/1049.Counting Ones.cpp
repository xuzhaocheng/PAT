#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <set>
#include "stdlib.h"

using namespace std;

int oneCounter(int n) {
	int cnt = 0;
	int digit = 1;
	int higher, lower, cur;

	while (n / digit != 0) {
		higher = n / (digit * 10);
		lower = n - (n / digit) * digit;
		cur = (n / digit) % 10;
		if (cur == 0) {
			cnt += higher * digit;
		} else if (cur == 1) {
			cnt += higher * digit + lower + 1;
		} else {
			cnt += (higher + 1)* digit;
		}
		digit *= 10;
	}

	return cnt;
}

int main(void) {
	// freopen("../in/1049.in", "r", stdin);
	
	int n;
	cin >> n;
	
	cout << oneCounter(n) << endl;
	return 0;
}