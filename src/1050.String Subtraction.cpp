/*
** 对于每个s1中的字符，用一个map做索引，key为字符，value为这个字符在s1中的所有位置的下标
** 对于输入的每个s2中的字符，利用索引计算出不输出的字符的下表，存在set中，避免重复。
** 输出的时候比较set中的值和s1的下标，相等则不输出，同时将set的指针后移。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <set>
#include "stdlib.h"

using namespace std;


int main(void) {
	// freopen("../in/1050.in", "r", stdin);
	
	unordered_map<char, vector<int> > charIndice;
	char ch;
	string s1;
	
	while ((ch = getchar()) != '\n') {
		charIndice[ch].push_back(s1.size());
		s1.push_back(ch);
	}

	set<int> noOutputIndice;
	while ((ch = getchar()) != '\n') {
		for (int i = 0; i < charIndice[ch].size(); i++)
			noOutputIndice.insert(charIndice[ch][i]);
	}


	bool flag = false;
	set<int>::iterator it = noOutputIndice.begin();
	for (int i = 0; i < s1.size(); i++) {
		if (it == noOutputIndice.end() || i != *it) {
			printf("%c", s1[i]);
			flag = true;
		} else it++;
	}
	if (!flag) cout << "" << endl;

	return 0;
}