/*
** 以i作为起点开始累计i+1, i+2,...,j直到sum大于等于m的时候，比较sum-m和当前最小的差值
** 如果sum - m < min_diff，则清空结果，在结果集里加入新的解(i, j)
** 如果sum -m == min_diff，则加入一个新的解(i, j)
** 计算累加和的时候可以利用上一次的结果，
** 若 i + (i+1) + ... + j >= sum 且 i + (i+1) + ... + (j-1) < sum
** 那么 (i+1) + (i+2) + ... + (j-1) < sum
** 则i + 1可以从j开始往后加
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

struct Pair {
	int i;
	int j;
	Pair(int ii, int jj) : i(ii), j(jj) {}
};

int main(void) {
	// freopen("../in/1044.in", "r", stdin);
	
	int n, m;
	cin >> n >> m;

	vector<int> diamonds(n);
	for (int i = 0; i < n; i++)
		cin >> diamonds[i];

	int min_diff = INT_MAX;
	int sum = 0;
	vector<Pair> results;
	int j = 0;
	for (int i = 0; i < n; i++) {
		for (; j < n; j++) {
			sum += diamonds[j];
			if (sum >= m) {
				if (sum - m <= min_diff) {
					if (sum - m < min_diff) {
						results.clear();
						min_diff = sum - m;
					}
					Pair p(i+1, j+1);
					results.push_back(p);
				}
				sum -= diamonds[j] + diamonds[i];
				break;
			}
		}
	}	

	for (int i = 0; i < results.size(); i++) {
		printf("%d-%d\n", results[i].i, results[i].j);
	}


	return 0;
}