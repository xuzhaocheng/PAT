/*
** 注意amounts用浮点数
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

struct mooncake {
	double amounts;
	double unit_price;
	double price;
};

bool cmp (const mooncake &x, const mooncake &y) {
	return x.unit_price > y.unit_price;
}

int main(void) {
	// freopen("../in/1070.in", "r", stdin);
	int n, d;
	cin >> n >> d;

	vector<mooncake> mooncakes(n);
	for (int i = 0; i < n; i++)
		cin >> mooncakes[i].amounts;

	double price;
	for (int i = 0; i < n; i++) {
		cin >> price;
		mooncakes[i].unit_price = price / mooncakes[i].amounts;
		mooncakes[i].price = price;
	}

	std::sort(mooncakes.begin(), mooncakes.end(), cmp);

	double total = 0;
	double profit = 0;
	for (int i = 0; i < mooncakes.size(); i++) {
		if (total + mooncakes[i].amounts <= d) {
			profit += mooncakes[i].price;
			total += mooncakes[i].amounts;
		} else {
			int amounts = d - total;
			profit += amounts / (double)mooncakes[i].amounts * mooncakes[i].price;
			break;
		}
	}
	printf("%.2f\n", profit);
	return 0;
}