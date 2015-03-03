#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int counts[100001];
int suppliers[100001];

int maxLevel;


void dfs(vector<vector<int> > &child, int i, int cnt, int &total) {
	if (child[i].size() == 0) {
		if (maxLevel < cnt) {
			maxLevel = cnt;
			total = 1;
		} else if (maxLevel == cnt) {
			total++;
		}
	}
	for (int j = 0; j < child[i].size(); j++) {
		dfs(child, child[i][j], cnt+1, total);
	}
}

int main(void) {

	freopen("d:\\Highest Price in Supply Chain.in", "r", stdin);
	int n, root;
	double p, r;
	cin >> n;
	cin >> p;
	cin >> r;
	r = r / 100;


	vector<vector<int> > child(n);
	maxLevel = 0;
	for (int i = 0; i < n; i++) {
		int index;
		cin >> index;
		if (index != -1)
			child[index].push_back(i);
		else 
			root = i;
	}

	int total = 0;
	dfs(child, root, 0, total);

	printf("%.2f %d", p * pow(r+1, maxLevel), total);
	return 0;
}

