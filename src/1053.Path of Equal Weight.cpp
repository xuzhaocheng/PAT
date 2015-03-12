/*
** 将每个结点的孩子结点按照孩子结点的权值降序排序
** 然后再遍历得到的结果就是按照题目要求有序的
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

vector<vector<int> > res;
vector<int> weight;

bool cmp(const int &x, const int &y) {
	return weight[x] > weight[y];
}

void traverse(const vector<int> &w, const vector<vector<int> > &leaves, int node, int target, vector<int> &path) {
	target -= w[node];

	if (target < 0)	return;

	path.push_back(w[node]);

	if (leaves[node].empty()) {
		if (target == 0)
			res.push_back(path);
		path.pop_back();
		return ;
	}

	for (int i = 0; i < leaves[node].size(); i++) {
		traverse(w, leaves, leaves[node][i], target, path);
	}

	path.pop_back();

}

int main(void) {
	// freopen("../in/1053.in", "r", stdin);
	int n, m, s;
	cin >> n >> m >> s;

	vector<int> w(n);
	vector<vector<int> > leaves(n);
	for (int i = 0; i < n; i++) 
		cin >> w[i];
	weight = w;

	int nodeNO;
	int k;
	for (int i = 0; i < m; i++) {
		cin >> nodeNO >> k;
		vector<int> l(k);
		for (int j = 0; j < k; j++) {
			cin >> l[j];
		}
		std::sort(l.begin(), l.end(), cmp);
		leaves[nodeNO] = l;
	}

	vector<int> path;
	traverse(w, leaves, 0, s, path);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
			if (j != res[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}