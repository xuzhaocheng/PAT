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
** 注意末尾的情况，typed已经完了，original还没完，那部分也算是worn out
*/
int main(void) {
	freopen("../in/1084.in", "r", stdin);
	string original;
	string typed;
	cin >> original;
	cin >> typed;

	int i, j;
	i = j = 0;
	string worn_out;
	while (i < original.size()) {
		if (j >= typed.size() || original[i] != typed[j]) {
			char c = original[i];
			if (original[i] <= 'z' && original[i] >= 'a') 
				c = c - ('a' - 'A');
			if (std::find(worn_out.begin(), worn_out.end(), c) == worn_out.end()) {
				worn_out.push_back(c);
			}
			i++;
		} else {
			i++, j++;
		}
	}
	cout << worn_out << endl;
	return 0;
}