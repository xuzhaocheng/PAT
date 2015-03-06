/*
** 使用dijkstra算法求出每个加油站到每个house的最短路径
** 筛选条件：
** 第一条件：所有候选点中到house最小值最大的那个候选点，第一个测试用例中G1的最小值为2， 
** G2的最小值为1，G3的最小值为2，所以选取候选点G1和G3继续比较； 
** 4 2 4 3 
** 3 1 3 4 
** 5 3 2 4 
** G1 
** 2.0 3.3 
** 第二条件：平均值最小，第一个测试用例中，G1的平均值小于G3，所以最优解为G3； 
** 第三条件：序号最小； 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

#define MAX_ARC 100000

using namespace std;

vector<int> dijtrask(vector<vector<int> > &arcs, int v0) {
	int n = arcs.size();
	vector<bool> final(n, false);
	vector<int> dist(n, MAX_ARC);

	for (int i = 1; i < n; i++) {
		dist[i] = arcs[v0][i];
	}

	dist[v0] = 0;
	final[v0] = true;
	for (int i = 2; i < n; i++) {
		int min_dist = MAX_ARC;
		int k;
		for (int j = 1; j < n; j++) {
			if (!final[j] && dist[j] < min_dist) {
				min_dist = dist[j];
				k = j;
			}
		}

		final[k] = true;
		for (int j = 1; j < n; j++) {
			if (!final[j] && min_dist + arcs[k][j] < dist[j]) {
				dist[j] = min_dist + arcs[k][j];
			}
		}

	}

	return dist;
}

// 之前忘记考虑超过一位数的index！最后一个case过不了
int getID(string str, int n) {
	int i = 0, len = str.size(), ID = 0;
	while(i < len) {
		if(str[i] != 'G')
		ID = ID * 10 + (str[i] - '0');
		i++;
	}
	if(str[0] == 'G')
		return n + ID;
	else
		return ID;
}

int main(void) {
	// freopen("../in/1072.in", "r", stdin);
	int n, m, k, Ds;
	cin >> n >> m >> k >> Ds;

	// house index为1~n, 加油站index为n~m+n
	vector<vector<int> > arcs(n+m+1, vector<int>(n+m+1, MAX_ARC));
	string p1, p2;
	int p1_index, p2_index;
	int dist;
	for (int i = 0; i < k; i++) {
		cin >> p1 >> p2 >> dist;
		p1_index = getID(p1, n);
		p2_index = getID(p2, n);
		arcs[p1_index][p2_index] = arcs[p2_index][p1_index] = dist;
	}

	int min_max_index = -1;
	double min_avg = MAX_ARC, min_max = 0;
	for (int i = n + 1; i <= m + n; i++) {
		vector<int> dists = dijtrask(arcs, i);

		double min = MAX_ARC;
		double sum = 0;
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (dists[j] > Ds) {
				flag = false;
				break;
			}
			
			if (dists[j] < min)
				min = dists[j];

			sum += dists[j];
		}
		if (flag) {
			if (min_max < min) {
				min_max = min;
				min_avg = sum / n;
				min_max_index = i;
			} else if (min_max == min) {
				if (min_avg > sum / n) {
					min_max_index = i;
					min_avg = sum / n;
				}
			}
		}
	}

	if (min_max_index == -1) {
		cout << "No Solution" << endl;
	} else {
		cout << "G" << min_max_index - n << endl;
		printf("%.1f %.1f\n", min_max, min_avg);
	}

	return 0;
}