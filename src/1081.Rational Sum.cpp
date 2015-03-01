#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

/*
** 通分相加
** 注意点：求gcd的时候判断a，b是否为0，是否为正数。
** 输出的时候整数和小数部分的符号。
*/
long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) return 1;
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a < b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}
	long long r = a % b;
	while (r > 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main(void) {
	freopen("../in/1081.in", "r", stdin);
	int n;
	cin >> n;

	long long a, b, aa, bb;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			scanf("%lld/%lld", &aa, &bb);
		} else {
			scanf("%lld/%lld", &a, &b);
			if (a == 0) continue;
			long long a1 = a * bb + aa * b;
			long long b1 = b * bb;
			long long gcd_aabb = gcd(a1, b1);
			aa = a1 / gcd_aabb;
			bb = b1 / gcd_aabb;
		}
	}

	if (aa == 0)
		cout << 0;
	else {
		if (aa / bb != 0) {
			cout << aa / bb;
			aa = abs(aa) % bb;
			if (aa % bb != 0)
				cout << " ";
		}
		if (aa % bb != 0) {
			cout << aa << "/" << bb; 
		}
	}
	return 0;
}