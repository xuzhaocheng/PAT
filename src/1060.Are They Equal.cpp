/*
** 0.1111 9.333 0000.2 0002928
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

/*
** 清除不必要的0
*/
string preProcessNumber(string s) {
	string res;
	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (flag || s[i] != '0') {
			flag = true;
			res.push_back(s[i]);
		}
	}
	if (res[0] == '.') 
		res.insert(res.begin(), '0');
	return res;
}


int findDotIndex(string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			return i;
		}
	}
	return s.size();
}

string intToString(int n) {
	char s[100];
	sprintf(s, "%d", n);
	string res(s);
	return res;
}

string scientificNumber(string s, int dotIndex, int n) {
	string res;
	res.append("0.");
	if (dotIndex == 1 && s[0] == '0') {
		int i;
		for (i = 2; i < s.size() && s[i] == '0'; i++);
		int lengthDotNeedToBeMoved = i == s.size() ? 0 : i - dotIndex - 1;
		int cnt = 0;
		while (cnt < n && i < s.size()) {
			res.push_back(s[i]);
			cnt++;
			i++;
		}

		while (cnt < n) {
			res.push_back('0');
			cnt++;
		}
		res.append("*10^");
		// 0就不用加“-”
		if (lengthDotNeedToBeMoved != 0)
			res.push_back('-');
		res.append(intToString(lengthDotNeedToBeMoved));
	} else {
		int cnt = 0;
		for (int i = 0; cnt < n && i < s.size(); i++) {
			// 避免加“.”到输出中
			if (s[i] != '.') {
				res.push_back(s[i]);
				cnt++;
			}
		}
		while (cnt < n) {
			res.push_back('0');
			cnt++;
		}
		res.append("*10^");
		res.append(intToString(dotIndex));
	}
	return res;
}

int main(void) {
	// freopen("../in/1060.in", "r", stdin);
	
	int n;
	string a, b;
	cin >> n >> a >> b;

	if (n == 0) {
		cout << "YES 0.0*10^0" << endl;
		return 0;
	}

	a = preProcessNumber(a);
	b = preProcessNumber(b);

	int dotIdxOfa, dotIdxOfb;
	dotIdxOfa = findDotIndex(a);
	dotIdxOfb = findDotIndex(b);

	string aa = scientificNumber(a, dotIdxOfa, n);
	string bb = scientificNumber(b, dotIdxOfb, n);

	if (aa == bb) {
		cout << "YES " << aa << endl;
	} else {
		cout << "NO " << aa << " " << bb << endl;
	}

	return 0;
}