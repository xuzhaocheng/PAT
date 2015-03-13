/*
** 最长公共子序列的变种
** 最长公共子序列有如下递推公式
** c[i][j]，i, j分别表示串favoriteStripe和colorStripe的下标
** 1) x[i] == y[j], c[i][j] = c[i-1][j-1]+1
** 2) x[i] != y[j], c[i][j] = max(c[i-1][j], c[i][j-1])
** 3) i == 0 || y == 0, c[i][j] = 0
** 按照题意，可以出现重复的元素。所以如果出现x[i] == y[j]的情况时，
** 就不是等于c[i-1][j-1]+1了，而是等于max(c[i][j-1]+1, c[i-1][j])
** x0,x1,x2,...,xi-1,xi+1
** y0,y1,y2,...,yj-1
** -----------------------
** x0,x1,x2,...,xi-1
** y0,y1,y2,...,yj-1,yj
** 而这题中favoriteStripe不会出现重复的元素，所以不用考虑c[i-1][j]，
** c[i][j]此时就等于c[i][j-1]+1了
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

int lcs(const vector<int> &favoriteColorStripe, const vector<int> &colorStripe) {
	int n = favoriteColorStripe.size();
	int m = colorStripe.size();
	vector<vector<int> > lens(n+1, vector<int>(m+1, 0));

	int max_lens;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (favoriteColorStripe[i-1] == colorStripe[j-1]) {
				lens[i][j] = lens[i][j-1] + 1;
			} else {
				lens[i][j] = max(lens[i-1][j], lens[i][j-1]);;
			}
		}
	}

	return lens[n][m];
}

int main(void) {
	// freopen("../in/1045.in", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	vector<int> favoriteColorStripe(m);
	for (int i = 0; i < m; i++) {
		cin >> favoriteColorStripe[i];
	}

	int l;
	cin >> l;
	vector<int> colorStripe;
	int color;
	for (int i = 0; i < l; i++) {
		cin >> color;
		colorStripe.push_back(color);
	}


	cout << lcs(favoriteColorStripe, colorStripe) << endl;

	return 0;
}