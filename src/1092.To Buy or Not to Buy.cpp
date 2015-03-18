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
	// freopen("../in/1092.in", "r", stdin);
	string a, b;
	cin >> a >> b;

	unordered_map<char, int> colorMap;
	for (int i = 0; i < b.size(); i++) {
		colorMap[b[i]]++;
	}

	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		unordered_map<char, int>::iterator it = colorMap.find(a[i]);
		if (it != colorMap.end()) {
			colorMap[a[i]]--;
			if (colorMap[a[i]] == 0)
				colorMap.erase(it);
		} else {
			cnt++;
		}
	}

	if (colorMap.size() != 0) {
		int sum = 0;
		unordered_map<char, int>::iterator it;
		for (it = colorMap.begin(); it != colorMap.end(); it++)
			sum += it->second;
		cout << "No " << sum << endl;
	} else {
		cout << "Yes " << cnt << endl;
	}
	return 0;
}