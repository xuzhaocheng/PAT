/*
** 把cout换成printf不超时
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

struct People {
	string ID;
	int virtue;
	int talent;
	int total;
};

bool cmp (const People &x, const People &y) {
	if (x.total != y.total)
		return x.total > y.total;
	if (x.virtue != y.virtue)
		return x.virtue > y.virtue;
	return x.ID < y.ID;
}

int main(void) {
	// freopen("../in/1062.in", "r", stdin);
	
	int n, l, h;
	vector<People> rank1, rank2, rank3, rank4;

	cin >> n >> l >> h;
	for (int i = 0; i < n; i++) {
		People p;
		cin >> p.ID;
		scanf("%d%d", &p.virtue, &p.talent);

		if (p.virtue < l || p.talent < l)
			continue;
		p.total = p.virtue + p.talent;
		if (p.virtue >= h && p.talent >= h) 
			rank1.push_back(p);
		else if (p.talent < h && p.virtue >= h)
			rank2.push_back(p);
		else if (p.talent < h && p.virtue < h && p.talent <= p.virtue)
			rank3.push_back(p);
		else 
			rank4.push_back(p);
	}

	std::sort(rank1.begin(), rank1.end(), cmp);
	std::sort(rank2.begin(), rank2.end(), cmp);
	std::sort(rank3.begin(), rank3.end(), cmp);
	std::sort(rank4.begin(), rank4.end(), cmp);

	cout << rank1.size() + rank2.size() + rank3.size() + rank4.size() << endl;
	for (int i = 0; i < rank1.size(); i++) {
		cout << rank1[i].ID << " ";
		printf("%d %d\n", rank1[i].virtue, rank1[i].talent);
	}
	for (int i = 0; i < rank2.size(); i++) {
		cout << rank2[i].ID << " ";
		printf("%d %d\n", rank2[i].virtue, rank2[i].talent);
	}
	for (int i = 0; i < rank3.size(); i++) {
		cout << rank3[i].ID << " ";
		printf("%d %d\n", rank3[i].virtue, rank3[i].talent);
	}
	for (int i = 0; i < rank4.size(); i++) {
		cout << rank4[i].ID << " ";
		printf("%d %d\n", rank4[i].virtue, rank4[i].talent);
	}
	return 0;
}