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
	freopen("../in/1077.in", "r", stdin);
	int n;
	cin >> n;
	vector<string> sentences(n);
	getchar();
	int min_len = 300;
	for (int i = 0; i < n; i++) {
		char ch;
		string str;
		while ((ch = getchar()) != '\n') {
			str.push_back(ch);
		}

		sentences[i] = str;
		if (sentences[i].size() < min_len)
			min_len = sentences[i].size();
	}

	string kuchiguse;

	for (int i = 0; i < min_len; i++) {
		int index = sentences[0].size() - i - 1;
		char ch = sentences[0][index];
		int j;
		for (j = 1; j < n; j++) {
			index = sentences[j].size() - i - 1;
			if (ch != sentences[j][index]) 
				break;
		}
		if (j != n)	break;
		kuchiguse.push_back(ch);
	}

	if (kuchiguse.size() != 0) {
		std::reverse(kuchiguse.begin(), kuchiguse.end());

		cout << kuchiguse;
	} else {
		cout << "nai";
	}


	return 0;
}