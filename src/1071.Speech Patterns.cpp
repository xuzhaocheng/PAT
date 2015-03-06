#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

struct word_info {
	string str;
	int counter;
	word_info(string s, int c) : str(s), counter(c) {}
};

inline char char_to_lower(char c) {
    return std::tolower(c);
}

bool cmp(const word_info &x, const word_info &y) {
	return x.str < y.str;
}

int main(void) {
	// freopen("../in/1071.in", "r", stdin);
	char ch;
	unordered_map<string, int> word_map;
	string str;
	while ((ch = getchar()) != EOF) {
		if ((ch >= '0' && ch <= '9') || 
			(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z')) {
			str.push_back(ch);
		} else if (str.size() != 0) {
			std::transform(str.begin(), str.end(), str.begin(), ::tolower);  
			word_map[str]++;
			str.clear();
		}
		if (ch == '\n') break;
	}

	unordered_map<string, int>::iterator it;
	vector<word_info> res;
	int max_cnt = 0;
	for (it = word_map.begin(); it != word_map.end(); it++) {
		if (max_cnt < it->second) {
			max_cnt = it->second;
			res.clear();
			word_info c(it->first, it->second);
			res.push_back(c);
		} else if (max_cnt == it->second) {
			word_info c(it->first, it->second);
			res.push_back(c);
		}
	}

	std::sort(res.begin(), res.end(), cmp);

	for (int i = 0; i < res.size(); i++)
		cout << res[i].str << " " << res[i].counter << endl;
	return 0;
}