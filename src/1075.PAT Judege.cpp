#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

struct User {
	string id;
	int total_score;
	int number_of_solved_problems;
	bool output_flag;
	unordered_map<int, int> scores;
	User() {
		total_score = number_of_solved_problems = 0;
		output_flag = false;
	}
};

bool cmp(const User &x, const User &y) {
	if (x.total_score != y.total_score)
		return x.total_score > y.total_score;
	if (x.number_of_solved_problems != y.number_of_solved_problems)
		return x.number_of_solved_problems > y.number_of_solved_problems;
	return x.id < y.id;
}

int main(void) {
	// freopen("../in/1075.in", "r", stdin);
	int n, k, m;	// number of users, number of problems, number of submittions
	cin >> n >> k >> m;

	vector<int> problem_scores(k+1);
	for (int i = 1; i <= k; i++) {
		cin >> problem_scores[i];
	}

	unordered_map<string, User> users;
	int problem_id, partial_score_obtained;
	string user_id;
	for (int i = 0; i < m; i++) {
		cin >> user_id;
		cin >> problem_id;
		cin >> partial_score_obtained;


		if (users.find(user_id) == users.end()) {
			User user;
			user.id = user_id;
			users[user_id] = user;
		}

		// 只要有一题过了编译，就能进行排名
		if (partial_score_obtained != -1) {
			users[user_id].output_flag = true;
		}

		// 已经提交过	
		if (users[user_id].scores.find(problem_id) != users[user_id].scores.end()) {
			// 得分比之前的高
			if (users[user_id].scores[problem_id] < partial_score_obtained) {
				// 更新得分和总分
				users[user_id].total_score += partial_score_obtained - users[user_id].scores[problem_id];		
				users[user_id].scores[problem_id] = partial_score_obtained;	

				// 若是满分更新解决的问题数
				if (partial_score_obtained == problem_scores[problem_id]) {
					users[user_id].number_of_solved_problems++;
				}	
			}
		} else {
			// 第一次提交
			if (partial_score_obtained == -1) {
				// 编译错误
				users[user_id].scores[problem_id] = 0;
			} else {
				// 更新成绩和总分
				users[user_id].scores[problem_id] = partial_score_obtained;
				users[user_id].total_score += partial_score_obtained;
			}

			// 满分，更新解决的问题数
			if (partial_score_obtained == problem_scores[problem_id]) {
				users[user_id].number_of_solved_problems++;
			}
		}		

	}

	// 用vector来排序
	vector<User> v_users;
	unordered_map<string, User>::iterator it;
	for (it = users.begin(); it != users.end(); it++) {
		v_users.push_back(it->second);
	}

	std::sort(v_users.begin(), v_users.end(), cmp);

	int rank = 1;
	for (int i = 0; i < v_users.size(); i++) {
		// 更新rank
		if (i > 0 && v_users[i].total_score < v_users[i-1].total_score)
			rank = i + 1;

		if (!v_users[i].output_flag) continue;
		
		cout << rank << " " << v_users[i].id << " " << v_users[i].total_score << " ";
		for (int j = 1; j <= k; j++) {
			if (v_users[i].scores.find(j) != v_users[i].scores.end()){
				cout << v_users[i].scores[j];
			} else {
				cout << "-";
			}
			if (j != k)	cout << " ";
		}
		cout << endl;
	}

	return 0;
}