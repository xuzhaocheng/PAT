/*
** 找每组中最大的值，直到选手人数为1
** 每次开始比赛时，先将这次比赛选手的名次置为可能的最低名次
** rank = winnerNumber + 1;
** 然后选出每组的获胜人数，继续迭代。
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

int findMax(const vector<int> &rice, const vector<int> &order, int begin, int end) {
	int max = 0;
	int idx = begin;
	for (int i = begin; i <= end; i++){
		if (rice[order[i]] > max) {
			max = rice[order[i]];
			idx = i;
		}
	}
	return order[idx];
}

int main(void) {
	// freopen("../in/1056.in", "r", stdin);
	
	int np, ng;
	scanf("%d %d", &np, &ng);

	vector<int> rice(np);
	vector<int> order(np);
	vector<int> rank(np, 0);
	for (int i = 0; i < np; i++)
		scanf("%d", &rice[i]);

	for (int i = 0; i < np; i++)
		scanf("%d", &order[i]);

	while (order.size() > 1) {
		vector<int> tmp;
		int winnerNumber = order.size() % ng == 0 ? order.size() / ng : order.size() / ng + 1;
		for (int i = 0; i < order.size(); i++) {
			rank[order[i]] = winnerNumber + 1;
		}

		for (int i = 0; i < order.size(); i += ng) {
			int end;
			if (i + ng - 1 >= order.size()) {
				end = order.size() - 1;
			} else {
				end = i + ng - 1;
			}
			int winner = findMax(rice, order, i, end);
			tmp.push_back(winner);
		}
		order = tmp;
	}
	rank[order[0]] = 1;

	for (int i = 0; i < rank.size(); i++) {
		cout << rank[i];
		if (i != rank.size() - 1)
			cout << " ";
	}
	cout << endl;
	return 0;
}