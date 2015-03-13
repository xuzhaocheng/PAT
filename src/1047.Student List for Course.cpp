#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <set>
#include "stdlib.h"
#include "string.h"

using namespace std;

struct Student{
	char name[5];
	vector<int> c;
};

bool cmp(const Student &x, const Student &y) {
	return strcmp(x.name, y.name) < 0;
}

int main(void) {
	// freopen("../in/1047.in", "r", stdin);
	int n, k;
	cin >> n >> k;

	int c, courseNO;
	char name[5];
	vector<vector<char *> > courses(k);
	vector<Student> students(n);

	for (int i = 0; i < n; i++) {
		Student s;
		scanf("%s%d", s.name, &c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &courseNO);
			s.c.push_back(courseNO);
		}
		students[i] = s;
	}

	std::sort(students.begin(), students.end(), cmp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < students[i].c.size(); j++) {
			courseNO = students[i].c[j];
			courses[courseNO-1].push_back(students[i].name);
		}
	}

	for (int i = 0; i < k; i++) {
		printf("%d %lu\n", i + 1, courses[i].size());
		if (!courses[i].empty()) {
			for (int j = 0; j < courses[i].size(); j++)
				printf("%s\n", courses[i][j]);
		}
	}

	return 0;
}