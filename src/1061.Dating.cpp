/*
** s1和s2第一个相同的[A, G]的字母表示星期几
** s1和s2第二个相同的[0, 9]∪[A, N]的字母表示小时
** s3和s4第一个相同的[A, Z]∪[a, z]的字母的下表表示分钟 
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
	// freopen("../in/1061.in", "r", stdin);
	string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	string a, b, c, d;
	cin >> a >> b >> c >> d;

	int i, j, cnt;

	i = j = cnt = 0;
	while (i < a.size() && j < b.size() && cnt < 2) {
		if (cnt == 0 && a[i] >= 'A' && a[i] <= 'G' && a[i] == b[j]) {
			cout << days[a[i] - 'A'] << " ";
			cnt++;
		} else if (cnt == 1 && a[i] == b[j] &&
		 ((a[i] >= 'A' && a[i] <= 'N') || (a[i] >= '0' && a[i] <= '9'))) {
			if (a[i] >= '0' && a[i] <= '9')
				cout << "0" << a[i] << ":";
			else 
				cout << a[i] - 'A' + 10 << ":";
		 	cnt++;
		}
		i++, j++;
	}

	i = j = 0;
	while (i < c.size() && j < d.size()) {
		if (((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')) &&
		     c[i] == d[j]) {
			printf("%02d\n", i);
			break;
		}
		i++, j++;
	}

	return 0;
}