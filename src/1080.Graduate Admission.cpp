#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

struct Student {
	int index;
	int ge;
	int gi;
	double grade;
	vector<int> p_schools;
};
Student students[40001];

int n, m, k;

bool cmp(const Student &x, const Student &y) {
	if (x.grade != y.grade)	return x.grade > y.grade;
	return x.ge > y.ge;
}

bool cmp1(const int x, const int y) {
	return students[x].index < students[y].index;
}

/*
** 排序后从高往低，从第一志愿往最后志愿取
*/
int main(void) {
	freopen("../in/1080.in", "r", stdin);
	cin >> n >> m >> k;

	vector<int> quotas;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		quotas.push_back(num);
	}

	int ge, gi, s;
	for (int i = 0; i < n; i++) {
		cin >> ge >> gi;
		students[i].index = i;
		students[i].ge = ge;
		students[i].gi = gi;
		students[i].grade = (ge + gi) / 2;
		for (int j = 0; j < k; j++) {
			cin >> s;
			students[i].p_schools.push_back(s);
		}
	}

	std::sort(students, students + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << students[i].grade << " " << students[i].ge << " " << students[i].gi << " ";
		for (int j = 0; j < students[i].p_schools.size(); j++)
			cout << students[i].p_schools[j] << " ";
		cout << endl;
	}
	cout << endl;
	

	vector<vector<int> > admissions(m);
	bool flags[m];
	for (int i = 0; i < m; i++) {
		flags[i] = true;
		if (quotas[i] == 0)
			flags[i] = false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < students[i].p_schools.size(); j++) {
			int school = students[i].p_schools[j];
			if (admissions[school].size() < quotas[school]) {
				admissions[school].push_back(i);
				break;
			} else if (flags[school]) {
				int last_student = admissions[school][quotas[school]-1];
				if (students[i].grade == students[last_student].grade &&
					students[i].ge == students[last_student].ge) {
					admissions[school].push_back(i);
					break;
				} else {
					flags[school] = false;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		std::sort(admissions[i].begin(), admissions[i].end(), cmp1);
		for (int j = 0; j < admissions[i].size(); j++) {
			cout << students[admissions[i][j]].index;
			if (j != admissions[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}