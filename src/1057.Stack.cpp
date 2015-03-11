/*
** 这题时间扣的很紧
** 使用multiset, 输入用scanf, 输出用printf, 注意超时
** 用搜索树好像也能过
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include <set>
#include "stdlib.h"

using namespace std;

/*
** 根据快排改的partition
** 超时
*/
/*
int partition(vector<int> &s, int p, int r, int k) {
	int i = p - 1;
	int j = p;

	while (j < r) {
		if (s[j] <= s[r]) {
			swap(s[++i], s[j]);
		}
		j++;
	}

	swap(s[++i], s[r]);

	if (i - p + 1 == k) {
		return s[i];
	} else if (i - p + 1 > k) {
		return partition(s, p, i-1, k);
	} else {
		return partition(s, i+1, r, k-(i-p+1));
	}
}
*/

void adjust(multiset<int> &min, multiset<int> &max, const stack<int> &s, int &median) {
	multiset<int>::iterator it;
	if (max.size() + 1 < min.size()) {
		it = min.end();
		it--;
		max.insert(*it);
		min.erase(it);
	} else if (max.size() > min.size()) {
		it = max.begin();
		min.insert(*it);
		max.erase(it);
	}

	if (s.size() > 0) {
		it = min.end();
		it--;
		median = *it;
	}
}

int main(void) {
	// freopen("../in/1057.in", "r", stdin);
	
	int n;
	cin >> n;

	stack<int> s;
	char op[10];
	int x, median;
	multiset<int> min, max;
	multiset<int>::iterator it;

	for (int i = 0; i < n; i++) {
		scanf("%s", op);
		if (op[1] == 'o') {
			if (s.empty()) {
				printf("Invalid\n");
			} else {
				int top = s.top();
				printf("%d\n", top);
				s.pop();

				if (median >= top) {
					it = min.find(top);
					min.erase(it);
				} else {
					it = max.find(top);
					max.erase(it);
				}
				adjust(min, max, s, median);
			}
		} else if (op[1] == 'e') {
			if (!s.empty()) {
				printf("%d\n", median);
			} else {
				printf("Invalid\n");
			}
		} else if (op[1] == 'u') {
			scanf("%d", &x);
			if (s.empty()) {
				min.insert(x);
				median = x;
			} else {
				if (median < x)
					max.insert(x);
				else 
					min.insert(x);
			}
			s.push(x);
			adjust(min, max, s, median);
		}
	}

	return 0;
}