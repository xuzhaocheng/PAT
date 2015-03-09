/*
** 考察set的使用
** unordered_map超时
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

void calcSetSimilarity(set<string> &x, set<string> &y) {
	int size = max(x.size(), y.size());
	vector<string> v(size);
	vector<string>::iterator it;

	it = std::set_intersection(x.begin(), x.end(), y.begin(), y.end(), v.begin());
	
	int intersection_size = it - v.begin();
	// 并集个数等于相加减交集个数
	
	double total = x.size() + y.size() - intersection_size;
	printf("%.1f%%\n", intersection_size / total * 100);
}

int main(void) {
	freopen("../in/1063.in", "r", stdin);
	
	int n;
	cin >> n;

	vector<set<string> > sets(n);
	int m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		set<string> set;
		string str_num;
		for (int j = 0; j < m; j++) {
			cin >> str_num;
			set.insert(str_num);
		}
		sets[i] = set;
	}

	int k;
	cin >> k;
	int idx1, idx2;
	for (int i = 0; i < k; i++) {
		cin >> idx1 >> idx2;
		calcSetSimilarity(sets[idx1 - 1], sets[idx2 - 1]);
	}

	return 0;
}