#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include <queue>
#include "stdlib.h"

using namespace std;

struct node {
	int id;
	int level;
	node(int i, int l):id(i),level(l) {};
};

/*
** BFS
** 计算level层内间接关注者的总转发次数
** 节点出队列后计算其关注者的转发数
** 若其关注者的关注者还在计数范围内则入队列，否则不入
** 注意需标识已访问过的节点，避免重复计算
*/
void bfs(vector<vector<int> > &followers, int userID, int level) {
	queue<node> q;
	int l = 0;
	vector<bool> visited(followers.size()+1, false);
	int cnt = 0;

	node nde(userID, l);
	q.push(nde);
	visited[userID] = true;

	while (!q.empty()) {
		node top = q.front();
		q.pop();

		for (int i = 0; i < followers[top.id].size(); i++) {
			int index = followers[top.id][i];
			
			if (visited[index])	continue;
			visited[index] = true;

			l = top.level + 1;
			if (l < level) {
				node cur(index, l);
				q.push(cur);
			}
			cnt++;
		}
	}
	cout << cnt << endl;
}

int main(void) {
	freopen("../in/1076.in", "r", stdin);
	int n, l;
	cin >> n >> l;

	vector<vector<int> > followers(n+1); 
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		int user;
		for (int j = 0; j < num; j++) {
			cin >> user;
			followers[user].push_back(i+1);
		}
	}

	cin >> num;
	for (int i = 0; i < num; i++) {
		int id;
		cin >> id;
		bfs(followers, id, l);
	}


	
	return 0;
}