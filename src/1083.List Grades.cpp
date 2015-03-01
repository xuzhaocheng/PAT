#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

struct student_info {
	string name;
	string ID;
	int grade;
};

bool cmp(const student_info &s1, const student_info &s2) {
	return s1.grade > s2.grade;
}

int main(void) {
	freopen("../in/1083.in", "r", stdin);
	vector<student_info> students;
	int n;
	cin >> n;

	int grade1, grade2;
	for (int i = 0; i < n; i++) {
		student_info info;
		cin >> info.name >> info.ID >> info.grade;
		students.push_back(info);
	}
	cin >> grade1 >> grade2;

	std::sort(students.begin(), students.end(), cmp);

	vector<int> res;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].grade <= grade2 && students[i].grade >= grade1) {
			res.push_back(i);
		}

	}

	for (int i = 0; i < res.size(); i++) 
		cout << students[res[i]].name << " " << students[res[i]].ID << endl;

	if (res.size() == 0)
		cout << "NONE" << endl;
	return 0;
}