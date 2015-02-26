#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <unordered_map>
using namespace std;

#define MAX_INT 1000000

bool final[201];
int arcs[201][201];
int dist[201];
vector<int> path[201];	// 记录最短路径的节点
int n, k;

vector<vector<int> > res;

void dijkstra(int v0) {
	for (int i = 0; i < n; i++) {
		final[i] = false;
		dist[i] = arcs[v0][i];
		if (dist[i] == MAX_INT) {
			path[i].push_back(-1);
		} else {
			path[i].push_back(v0);
		}
	}

	final[v0] = true;
	dist[v0] = 0;

	for (int i = 1; i < n; i++) {
		int min = MAX_INT;
		int v;
		for (int j = 0; j < n; j++) {
			if (!final[j]) {
				if (dist[j] < min) {
					v = j;
					min = dist[j];
				}
			}
		}

		final[v] = true;

		for (int j = 0; j < n; j++) {
			if (!final[j] && (min + arcs[v][j] <= dist[j])) {
				// 处理有多条最短路径的情况
				// Path存储当前节点在最短路径中的前驱节点，用vector记录有多条最短路径的情况
				if (min + arcs[v][j] < dist[j]) {
					dist[j] = min + arcs[v][j];
					path[j].clear();
				}
				path[j].push_back(v);
			}
		}
	}
}

void output_path(int j, vector<int> &s) {
	if (j == 0) {
		s.push_back(0);
		vector<int> tmp = s;
		res.push_back(s);
		s.pop_back();
		return;
	}

	s.push_back(j);
	for (int i = 0; i < path[j].size(); i++) {
		output_path(path[j][i], s);
	}
	s.pop_back();
}

int main(void) {
	freopen("1087.in", "r", stdin);
	unordered_map<string, int> city_map;
	vector<string> city_index;
	string start_city;
	int index = 0;

	cin >> n;
	cin >> k;
	cin >> start_city;

	city_map[start_city] = index;
	city_index.push_back(start_city);
	index++;

	string city;
	vector<int> happiness(n-1);
	happiness[0] = 0;

	int happy;
	for (int i = 0; i < n - 1; i++) {
		cin >> city;
		cin >> happy; 
		happiness[index] = happy;
		city_map[city] = index;
		city_index.push_back(city);
		index++;
	}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arcs[i][j] = MAX_INT;

	string frm, dest;
	int distance, frm_index, dest_index;
	for (int i = 0; i < k; i++) {
		cin >> frm;
		cin >> dest;
		cin >> distance;

		frm_index = city_map[frm];
		dest_index = city_map[dest];
		arcs[frm_index][dest_index] = arcs[dest_index][frm_index] = distance;
	}

	dijkstra(0);
	vector<int> s;
	output_path(city_map["ROM"], s);

	int max_happiness = 0, avg_happiness = 0;
	int res_index = -1;
	for (int i = 0; i < res.size(); i++) {
		int h = 0;
		for (int j = res[i].size() - 1; j >= 0; j--) {
			h += happiness[res[i][j]];
		}
		
		if (h > max_happiness) {
			max_happiness = h;
			avg_happiness = h / (res[i].size() - 1);
			res_index = i;
		} else if (h == max_happiness && h / (res[i].size() - 1) > avg_happiness) {
			avg_happiness = h / (res[i].size() - 1);
			res_index = i;
		}
	}

	cout << res.size() << " " << dist[city_map["ROM"]] << " " << max_happiness << " " << avg_happiness << endl;
	for (int i = res[res_index].size() - 1; i > 0; i--)
		cout << city_index[res[res_index][i]] << "->";
	cout << city_index[res[res_index][0]] << endl;
	return 0;
}