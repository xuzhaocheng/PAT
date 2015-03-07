/*
** 分两种情况
** 1. num[0] == 0，这时候将0和下一个未放好位置的元素交换位置（不影响已经放好位置的元素）
** 2. num[0] != 0，这时候将num[0]与num[num[0]]交换，直到num[0] == 0
** 3. 检查是否所有元素都已经放好位置。若不是，则重复第一步，否则结束。
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

/*
** 注意从上一个未排序的元素的位置开始搜！
*/
int find_first_unsorted_index(vector<int> &num, int begin, int end) {
	for (int i = begin; i < end; i++)
		if (num[i] != i) return i;
	return -1;
}

int main(void) {
	// freopen("../in/1067.in", "r", stdin);
	int n;
	cin >> n;
	
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	

	int cnt = 0;
	int first_unsorted_index = find_first_unsorted_index(num, 1, n);

	while (first_unsorted_index != -1) {
		if (num[0] == 0) {
			swap(num[0], num[first_unsorted_index]);
			cnt++;
		}

		while (num[0] != 0) {
			swap(num[0], num[num[0]]);
			cnt++;
		}

		first_unsorted_index = find_first_unsorted_index(num, first_unsorted_index, n);
	}	
	cout << cnt;

	return 0;
}

/*
** 没有从begin开始查找会超时，使用unordered_map来做也能AC
*/
/*
int main(void) {
	// freopen("../in/1067.in", "r", stdin);
	int n;
	cin >> n;
	
	vector<int> num(n);
	unordered_map<int, int> unsorted_idx;
	int total = n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (num[i] == i) {
			total--;
		} else if (i > 0) {
			unsorted_idx[i] = 1;
		}
	}

	int cnt = 0;
	while (total > 0) {
		if (num[0] == 0 && !unsorted_idx.empty()) {
			swap(num[0], num[unsorted_idx.begin()->first]);
			cnt++;
			total++;
		}

		int idx = 0;
		while (true) {
			int tmp = idx;
			idx = num[idx];
			num[tmp] = tmp;
			unordered_map <int, int>::iterator it = unsorted_idx.find(idx);
			if (it != unsorted_idx.end())
				unsorted_idx.erase(it);
			total--;
			if (idx == 0) break;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}*/