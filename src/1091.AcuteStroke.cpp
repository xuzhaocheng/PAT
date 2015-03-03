#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int z;
	int x;
	int y;
	Point(int z, int x, int y):z(z),x(x),y(y){}
};

int m, n, l, t;

/*
** dfs会造成段错误
*/
int dfs(vector<vector<vector<bool >>> &slices, int s, int i, int j, int cnt) {
	if (s >= l || i >= m || j >= n || s < 0 || i < 0 || j < 0) return cnt;	
	if (slices[s][i][j] == false)	return cnt;
	slices[s][i][j] = false;
	cnt++;
	cnt = dfs(slices, s, i + 1, j, cnt);
	cnt = dfs(slices, s, i, j + 1, cnt);
	cnt = dfs(slices, s, i - 1, j, cnt);
	cnt = dfs(slices, s, i, j - 1, cnt);
	cnt = dfs(slices, s + 1, i, j, cnt);
	cnt = dfs(slices, s - 1, i, j, cnt);

	return cnt;
}

/*
** 三维数组的连通问题
** 用一个辅助队列求解
*/
int bfs(vector<vector<vector<bool >>> &slices, int s, int i, int j) {
	int v = 0;
	queue<Point> q;
	if (slices[s][i][j] == true) {
		q.push(Point(s, i, j));
		slices[s][i][j] = false;
	}
	while (!q.empty()) {
		Point p = q.front();
		q.pop();
		int x = p.x;
		int y = p.y;
		int z = p.z;
		
		if (x > 0 && slices[z][x-1][y]) {
			q.push(Point(z, x-1, y));
			slices[z][x-1][y] = false;
		}
		if (x < m - 1 && slices[z][x+1][y]) {
			q.push(Point(z, x+1, y));
			slices[z][x+1][y] = false;
		}
		if (y > 0 && slices[z][x][y-1]) {
			q.push(Point(z, x, y-1));
			slices[z][x][y-1] = false;
		}
		if (y < n - 1 && slices[z][x][y+1]) {
			q.push(Point(z, x, y+1));
			slices[z][x][y+1] = false;
		}
		if (z > 0 && slices[z-1][x][y]) {
			q.push(Point(z-1, x, y));
			slices[z-1][x][y] = false;
		}
		if (z < l - 1 && slices[z+1][x][y]) {
			q.push(Point(z+1, x, y));
			slices[z+1][x][y] = false;
		}
		v++;
	}

	return v;
}

int main(void)
{
	freopen("d:\\Acute Stroke.in", "r", stdin);
	vector<vector<vector<bool >>> slices;

	cin >> m;
	cin >> n;
	cin >> l;
	cin >> t;
	for (int i = 0; i < l; i++) {
		vector<vector<bool> > slice;
		for (int j = 0; j < m; j++) {
			vector<bool> pixels;
			for (int k = 0; k < n; k++) {
				int p;
				cin >> p;
				pixels.push_back(p == 0 ? false : true);
			}
			slice.push_back(pixels);
		}
		slices.push_back(slice);
	}

	int res = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) { 
			for (int k = 0; k < n; k++) {
				int total = bfs(slices, i, j, k);
				
				if (total >= t)
					res += total;
			}
		}
	}
	cout << res << endl;

	return 0;
}

