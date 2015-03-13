/*
** 选定一个点作为起点(s)，逆时针（或者顺时针）计算他到每个点的距离(dist[])，同时计算环的总长度sum
** 对于给定的两个点(i, j)，根据用上一步得到的距离做差，dist_i_j = abs(dist[i] - dist[j])
** 然后取max(dist_i_j, sum - dist_i_j)就是所得的结果
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
** 最容易想到的方法 超时
*/
int calcDistance(vector<int> &distance, int origin, int dest, int totalLength) {
	int straight;
	straight = origin;
	
	int straightLength;
	straightLength = 0;

	int s_dest = dest;

	while (straight != s_dest) {
		straightLength += distance[straight];
		straight = (straight + 1) % distance.size();
	}

	return min(straightLength, totalLength - straightLength);

}


int main(void) {
	// freopen("../in/1046.in", "r", stdin);
	
	int n;
	cin >> n;
	vector<int> distance(n);
	vector<int> dist(n);
	dist[0] = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> distance[i];
		sum += distance[i];
		if (i + 1 != n) {
			dist[i+1] = sum;
		}
	}


	int m, origin, dest;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> origin >> dest;
		origin--, dest--;
		int dist_i_j = abs(dist[origin] - dist[dest]);
		dist_i_j = min(dist_i_j, sum - dist_i_j);
		printf("%d\n", dist_i_j);
		
	}

	return 0;
}