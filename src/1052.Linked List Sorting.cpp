/*
** 注意题目意思，给出的结点中可能存在由表头开始遍历不到的结点
** 那部分结点不在排序范围内。
** 注意链表为空或者待排序的链表为空时，输出0 -1
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

struct ListNode {
	string address;
	int key;
	string next;
};

bool cmp(const ListNode &x, const ListNode &y) {
	return x.key < y.key;
}

int main(void) {
	// freopen("../in/1052.in", "r", stdin);
	
	int n;
	string head;
	cin >> n >> head;

	if (n == 0) {
		cout << "0 -1" << endl;
		return 0;
	}

	vector<ListNode> list;
	unordered_map<string, ListNode> linkList(n);
	string address;

	for (int i = 0; i < n; i++) {
		cin >> address;
		ListNode node;
		node.address = address;
		cin >> node.key >> node.next;
		linkList[address] = node;
	}

	string next = head;
	while (next != "-1") {
		list.push_back(linkList[next]);
		next = linkList[next].next;
	}


	std::sort(list.begin(), list.end(), cmp);

	if (list.size() != 0) {
		cout << list.size() << " " << list[0].address << endl;
		for (int i = 0; i < list.size(); i++) {
			cout << list[i].address << " " << list[i].key << " ";
			if (i != list.size() - 1) {
				cout << list[i+1].address << endl;
			} else {
				cout << -1 << endl;
			}
		}
	} else {
		cout << "0 -1" << endl;
	}

	return 0;
}