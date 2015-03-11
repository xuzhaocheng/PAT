/*
** 维护一个ages数组，下标表示年龄，数组里使用set存放这个年龄下每个人的信息。因为是set，所以插入时就排好序了。
** 之后对于每个输入k [Amin, Amax]
** 对ages数组进行Amin - Amax + 1路归并排序，而且最多只用输出前面k个即可。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include <set>
#include "stdlib.h"
#include "string.h"

using namespace std;

struct People {
	string name;
	int age;
	int worth;
};

struct Compare {
	bool operator() (const People &x, const People &y) {
		if (x.worth != y.worth) return x.worth > y.worth;
		if (x.age != y.age) return x.age < y.age;
		return x.name < y.name;
	}
};

bool cmp(const People &x, const People &y) {
	if (x.worth != y.worth) return x.worth > y.worth;
	if (x.age != y.age) return x.age < y.age;
	return x.name < y.name;
}

bool isGreater(const set<People, Compare>::iterator &x, const set<People, Compare>::iterator &y) {
	if (x->worth != y->worth) return x->worth > y->worth;
	if (x->age != y->age) return x->age < y->age;
	return x->name < y->name;
}


int main(void) {
	// freopen("../in/1055.in", "r", stdin);
	int n, k;
	scanf("%d%d", &n, &k);

	vector<People> people(n);
	vector<set<People, Compare> > ages(201);
	char name[9];
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d", name, &people[i].age, &people[i].worth);
		string nm(name);
		people[i].name = nm;
		ages[people[i].age].insert(people[i]);
	}

	// 存储每个ages的起始下标
	vector<set<People, Compare>::iterator > indices(201);
	for (int i = 0; i < indices.size(); i++) {
		indices[i] = ages[i].begin();
	}

	int m, amin, amax;
	for (int i = 0; i < k; i++) {
		printf("Case #%d:\n", i + 1);
		scanf("%d%d%d", &m, &amin, &amax);

		vector<set<People, Compare>::iterator > tmp = indices;
		bool flag = false;
		int mm = m;
		while (m > 0) {
			int max_idx;
			flag = false;
			for (int j = amin; j <= amax; j++) {
				if (!ages[j].empty() && tmp[j] != ages[j].end()) {
					if (!flag) {
						max_idx = j;
						flag = true;
					} else {
						if (isGreater(tmp[j], tmp[max_idx])) {
							max_idx = j;
						}
					}
				}
			}

			if (!flag)	break;
			cout << tmp[max_idx]->name << " ";
			printf("%d %d\n", tmp[max_idx]->age, tmp[max_idx]->worth);
			tmp[max_idx]++;
			m--;
		}

		if (!flag && mm == m)
			printf("None\n");
	}
	return 0;
}