/*
** 可以分为前补0、后补0、不补0，三种情况
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


int main(void) {
	// freopen("../in/1073.in", "r", stdin);
	
	string fraction;
	int exponent;
	char ch;
		
	ch = getchar();
	if (ch == '-')
		cout << "-";

	while (true) {
		ch = getchar();
		if (ch != 'E') {
			fraction.push_back(ch);
		} else break;
	}
	cin >> exponent;

	int dot_index;
	for (dot_index = 0; dot_index < fraction.length() && fraction[dot_index] != '.'; dot_index++);

	// 后面补0的情况
	if (dot_index + exponent >= (int)fraction.length()) {
		int zero_number = dot_index + exponent - fraction.length() + 1;
		fraction.erase(fraction.begin() + dot_index);
		cout << fraction;
		for (int i = 0; i < zero_number; i++)
			cout << 0;
	} else if (dot_index + exponent <= 0) {
		// 前面补0
		cout << "0.";
		int zero_number = - (dot_index + exponent);
		for (int i = 0; i < zero_number; i++)
			cout << 0;
		fraction.erase(fraction.begin() + dot_index);
		cout << fraction;
	} else {
		// 不补0
		dot_index = dot_index + exponent;
		for (int i = 0; i < fraction.length(); i++) {
			if (fraction[i] != '.') {
				cout << fraction[i];
			}
			if (i == dot_index && i != fraction.length() - 1)
				cout << ".";
		}
	}

	return 0;
}