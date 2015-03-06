/*
** 运用string转int，int转string，以及string的排序就能解题
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"
#include "stdio.h"

using namespace std;

int str_to_int(string str) {
	int res = 0;
	for (int i = 0; i < str.length(); i++) {
		res = res * 10 + str[i] - '0';
	}
	return res;
}

string int_to_str(int num) {
	char s[4];
	sprintf(s, "%04d", num);
	string res(s);
	return res;
}

bool cmp (const char &x, const char &y) {
	return x > y;
}

int main(void) {
	// freopen("../in/1069.in", "r", stdin);
	int num;
	cin >> num;

	string str = int_to_str(num);
	string reverse_str, difference_str;
	int number, reverse_number, difference;

	while (true) {
		std::sort(str.begin(), str.end(), cmp);
		reverse_str = str;
		std::reverse(reverse_str.begin(), reverse_str.end());

		number = str_to_int(str);
		reverse_number = str_to_int(reverse_str);
		if (number < reverse_number) {
			swap(number, reverse_number);
			swap(str, reverse_str);
		}
		difference = number - reverse_number;
		difference_str = int_to_str(difference);
		cout << str << " - " << reverse_str << " = " << difference_str << endl;
		if (difference == 0 || difference == 6174)
			break;
		str = difference_str;
	}

	return 0;
}