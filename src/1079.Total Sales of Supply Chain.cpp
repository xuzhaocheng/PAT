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
** 用pre数组记录每个distributors or retailers的供应商，超时
int main(void) {
	freopen("../in/1079.in", "r", stdin);
	int n;
	double p, r;
	cin >> n >> p >> r;
	r /= 100;

	int k;
	int id, amount;
	vector<int> pre(n);
	vector<int> retailers;
	vector<int> amounts;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) {
			retailers.push_back(i);
			cin >> amount;
			amounts.push_back(amount);
			continue;
		} 
		for (int j = 0; j < k; j++) {
			cin >> id;
			pre[id] = i;
		}
	}

	double total = 0;

	for (int i = 0; i < retailers.size(); i++) {
		int cnt = 0;
		int supplier = retailers[i];
		while (supplier != 0) {
			supplier = pre[supplier];
			cnt++;
		}
		total += p * pow(1+r, cnt) * amounts[i];
	}

	printf("%.1f", total);
	return 0;
}
*/

/*
** DFS不超时，自顶向下遍历
*/
double r, p;
void dfs(unordered_map<int, int> &retailers, vector<vector<int> > &children, int i, int cnt, double &total) {
	if (children[i].size() == 0) {
		total += pow(1+r, cnt) * retailers[i] * p;
		return;
	}

	for (int j = 0; j < children[i].size(); j++) {
		dfs(retailers, children, children[i][j], cnt+1, total);
	}
}

int main(void) {
	freopen("../in/1079.in", "r", stdin);
	int n;
	cin >> n >> p >> r;
	r /= 100;

	int k;
	int id, amount;
	vector<vector<int> > children(n);
	unordered_map<int, int> retailers;

	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) {
			cin >> amount;
			retailers[i] = amount;
		} else {
			for (int j = 0; j < k; j++) {
				cin >> id;
				children[i].push_back(id);
			}
		}
	}

	double total = 0;
	dfs(retailers, children, 0, 0, total);

	printf("%.1f", total);

	return 0;
}