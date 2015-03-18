#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

struct Car {
	int time;
	string plate;
	int status; // 0 == in 1 == out
	int pair;
};

bool cmp(const Car &x, const Car &y) {
	return x.time < y.time;
}

void print(const vector<Car> &cars) {
	for (int i = 0; i < cars.size(); i++) {
		cout << cars[i].plate << " ";
		int hh, mm, ss;
		hh = cars[i].time / 3600;
		mm = (cars[i].time % 3600) / 60;
		ss = (cars[i].time % 3600) % 60;
		printf("%02d:%02d:%02d ", hh, mm, ss);
		if (cars[i].status == 0)	cout << "in";
		else cout << "out";
		cout << endl;
	}
	cout << endl;
}

int main(void) {
	// freopen("../in/1095.in", "r", stdin);
	int n, k;
	cin >> n >> k;

	vector<Car> cars(n);
	string plate;
	int hh, mm, ss;
	char in_or_out[5];
	for (int i = 0; i < n; i++) {
		Car car;
		cin >> car.plate;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		car.time = hh * 3600 + mm * 60 + ss;
		car.pair = -1;
		scanf("%s", in_or_out);
		if (in_or_out[0] == 'i') {
			car.status = 0;
		} else {
			car.status = 1;
		}
		cars[i] = car;
	}

	std::sort(cars.begin(), cars.end(), cmp);

	// print(cars);
	vector<Car> legalCars;
	for (int i = 0; i < n; i++) {
		if (cars[i].status == 1 && cars[i].pair != -1) {
			legalCars.push_back(cars[i]);
		} else if (cars[i].status == 0) {
			for (int j = i + 1; j < n; j++) {
				if (cars[i].plate == cars[j].plate) {
					if (cars[j].status == 1 && cars[j].pair == -1) {
						cars[j].pair = i;
						legalCars.push_back(cars[i]);
					}
					break;
				}
			}
		}
	}

	// print(legalCars);

	vector<int> queries(k);
	for (int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = hh * 3600 + mm * 60 + ss;
		queries[i] = time;
	}

	// vector<int> result;
	int cnt = 0;
	int q_idx = 0;
	int max_time = 0;
	unordered_map<string, int> park;
	vector<string> longestTime;
	for (int i = 0; i < legalCars.size(); i++) {
		// while (q_idx < queries.size() && queries[q_idx] < legalCars[i].time) {
		// 	result.push_back(cnt);
		// 	q_idx++;
		// }
		if (legalCars[i].status == 0) {
			cnt++;
			park[legalCars[i].plate] = legalCars[i].time;
		} else {
			if (max_time <= legalCars[i].time - park[legalCars[i].plate]) {
				if (max_time < legalCars[i].time - park[legalCars[i].plate]) {
					max_time = legalCars[i].time - park[legalCars[i].plate];
					longestTime.clear();
				}
				longestTime.push_back(legalCars[i].plate);
			}
			cnt--;
		}
	}

	// while (q_idx < queries.size()) {
	// 	result.push_back(0);
	// 	q_idx++;
	// }

	vector<int> result(24*3600, 0);
	cnt = 0;
	int idx = 0;

	for (int i = 0; i < 24 * 3600; i++) {
		while (idx < legalCars.size() && legalCars[idx].time == i) {
			if (legalCars[idx].status == 0) {
				cnt++;
			} else {
				cnt--;
			}
			idx++;
		}   
		result[i] = cnt;
	}
	// for (int i = 0; i < result.size(); i++) {
	// 	cout << result[i] << endl;
	// }

	for (int i = 0; i < queries.size(); i++) {
		cout << result[queries[i]] << endl;
	}

	std::sort(longestTime.begin(), longestTime.end());

	for (int i = 0; i < longestTime.size(); i++) {
		cout << longestTime[i] << " ";
	}

	hh = max_time / 3600;
	max_time %= 3600;
	mm = max_time / 60;
	ss = max_time % 60;
	printf("%02d:%02d:%02d\n", hh, mm, ss);
	return 0;
}