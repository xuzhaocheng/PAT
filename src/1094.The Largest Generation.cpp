#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <queue>
#include "stdlib.h"

using namespace std;

struct LevelNode {
	int l;
	int v;
	LevelNode(int level, int value) : l(level), v(value) {}
};

int main(void) {
	// freopen("../in/1094.in", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	if (n <= 1) {
		cout << "1 " << n << endl;
		return 0;
	}

	vector<vector<int> > children(n+1);
	int parent, k, child;
	for (int i = 0; i < m; i++) {
		cin >> parent >> k;
		for (int j = 0; j < k; j++) {
			cin >> child;
			children[parent].push_back(child);
		}
	}

	vector<int> result(n+1, 0);
	queue<LevelNode> q;
	LevelNode node(1, 1);
	q.push(node);

	while (!q.empty()) {
		LevelNode front = q.front();
		q.pop();
		parent = front.v;
		result[front.l]++;
		for (int i = 0; i < children[parent].size(); i++) {
			LevelNode ch(front.l + 1, children[parent][i]);
			q.push(ch);
		}
	}

	int max_cnt, max_level;
	max_cnt = 0;
	for (int i = 1; i < result.size(); i++) {
		if (result[i] > max_cnt) {
			max_level = i;
			max_cnt = result[i];
		}
	}

	cout << max_cnt << " " << max_level << endl;

	return 0;
}