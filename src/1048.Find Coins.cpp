/*
** 用unordered_map保存coins，key为面值，value为个数
** 对于每个输入，找m-value是否已经存在，若存在，则是一个解
** 比较当前最小的v1和当前解的v1的大小决定是否更新最优解
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"
#include <limits.h>

using namespace std;


int main(void) {
	// freopen("../in/1048.in", "r", stdin);

	int n, m;
	cin >> n >> m;

	unordered_map<int, int> coins(n);
	int value;
	int minV1 = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> value;
		if (coins.find(m - value) != coins.end()) {
			if (min(value, m - value) < minV1) {
				minV1 = min(value, m - value);
			}
		} 
		coins[value]++;
	}

	if (minV1 != INT_MAX)
		cout << minV1 << " " << m - minV1 << endl;
	else 
		cout << "No Solution" << endl;

	return 0;
}