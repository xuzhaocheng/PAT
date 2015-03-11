/*
** 用一个map来记录每个color出现的次数
** 记录出现最多的color，每次输入看情况更新color.
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

int main(void) {
	// freopen("../in/1054.in", "r", stdin);
	int m, n;
	cin >> m >> n;

	unordered_map<int, int> count;

	int pixel;
	int max_count = 0;
	int max_pixel;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &pixel);
			count[pixel]++;
			if (count[pixel] > max_count) {
				max_count = count[pixel];
				max_pixel = pixel;
			}
		}
	}

	cout << max_pixel << endl;
	return 0;
}