/*
** 背包问题
** dp[i][j]表示从前i个硬币中能挑选出的总值不超过j的最大总面值
** dp[i][j] = max(dp[i-1][j], dp[i-1][j-coins[i-1]]+coins[i-1])
** 最后dp[n][m]如果等于m则有解，否则无解。
** 用choice数组来记录选取的硬币
** choice[i][j]表示第i个硬币是否在dp[i][j]中被选入，也就是是否在前i个硬币
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

int main(void) {
	// freopen("../in/1068.in", "r", stdin);

	int n, m;
	cin >> n >> m;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) 
		cin >> coins[i];

	std::sort(coins.begin(), coins.end(), greater<int>());

	vector<vector<int> > dp(n+1, vector<int>(m+1));
	vector<vector<int> > choice(n+1, vector<int>(m+1, 0));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0)
				dp[i][j] = 0;
			else {
				if (j >= coins[i-1] && dp[i-1][j] <= dp[i-1][j-coins[i-1]]+coins[i-1]) {
					dp[i][j] = dp[i-1][j-coins[i-1]]+coins[i-1];
					choice[i][j] = 1;
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}

	if (dp[n][m] != m) {
		cout << "No Solution" << endl;
	} else {
		vector<int> res;

		int k = n, v = m;
		while (k > 0) {
			if (choice[k][v] == 1) {
				res.push_back(coins[k-1]);
				v -= coins[k-1];
			}
			k--;
		}
			
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i != res.size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}