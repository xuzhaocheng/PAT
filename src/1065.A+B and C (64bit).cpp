/*
** 考察string的加法和减法操作
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

bool cmp(const string &a, const string &b) {
	if (a.length() != b.length())
		return a.length() > b.length();
	return a > b;
}

string str_add(string a, string b) {
	if (a.length() < b.length())
		swap(a, b);

	int i = a.length() - 1;
	int j = b.length() - 1;

	int tens = 0;
	while (j >= 0) {
		a[i] = a[i] - '0' + b[j] - '0' + tens;
		tens = a[i] / 10;
		a[i] = a[i] % 10 + '0';
		i--, j--;
	}

	if (tens > 0) {
		while (i >= 0) {
			a[i] = a[i] - '0' + tens;
			tens = a[i] / 10;
			a[i] = a[i] % 10 + '0';
			i--;
		}
		if (tens > 0)
			a.insert(a.begin(), tens + '0');
	}
	return a;
}

string str_minus(string a, string b) {
	int flag = 1;
	if (!cmp(a, b)) {
		swap(a, b);
		flag = -1;
	}

	int len = max(a.length(), b.length());
	string res(len, '0');
	int i = a.length() - 1;
	int j = b.length() - 1;
	int tens = 0;

	len--;
	while (i >= 0 && j >= 0 && len >= 0) {
		res[len] = a[i] - b[j] - tens;
		if (res[len] < 0) {
			tens = 1;
			res[len] += 10;
		}
		res[len--] += '0';
		i--, j--;
	}

	while (i >= 0) {
		res[len] = a[i] - '0' - tens;
		if (res[len] < 0) {
			tens = 1;
			res[len] += 10;
		}
		res[len--] += '0';
		i--;
	}

	while (res[0] == '0' && res.size() > 1) 
		res.erase(res.begin());
	if (flag == -1)
		res.insert(res.begin(), '-');
	return res;
}

bool func(string a, string b, string c) {
	int flag = 1;
	if (a[0] == '-' && b[0] == '-') {
		a.erase(a.begin());
		b.erase(b.begin());
		flag = -1;
	}

	if (a[0] != '-' && b[0] != '-') {
		string sum = str_add(a, b);
		if (flag == 1) {
			if (c[0] == '-')
				return true;
			else 
				return cmp(sum, c);
		} else {
			if (c[0] != '-')
				return false;
			else {
				c.erase(c.begin());
				return cmp(c, sum);
			}
		}
	} else {
		string diff;
		if (a[0] == '-') {
			a.erase(a.begin());
			diff = str_minus(b, a);
		} else {
			b.erase(b.begin());
			diff = str_minus(a, b);
		}

		if (diff[0] == '-' && c[0] == '-') {
			diff.erase(diff.begin());
			c.erase(c.begin());
			return cmp(c, diff);
		}
		else if (diff[0] == '-' && c[0] != '-')
			return false;
		else if (diff[0] != '-' && c[0] == '-')
			return true;
		else 
			return cmp(diff, c);
	}
}

int main(void) {
	freopen("../in/1065.in", "r", stdin);

	int n;
	cin >> n;

	string a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		bool res = func(a, b, c);
		cout << "Case #" << i + 1 << ": ";
		if (res) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}