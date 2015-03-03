/*
** 链表倒置
** 方法是很快想出来了，把输入转成指针链表，使用表头法插元素，记录每段的头和尾，计数到K后重新设置头和尾。
** 都转完后将最后几个不必要转的重新转回来。
** 但是蛋疼的是题目的隐藏条件是不给开空间，也就是malloc不能使用（题目没说明！)。
** 但是我在存储的时候是开辟空间一个一个存的，本地正常，OJ一直报段错误，找了好久才反应过来。
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

struct Address {
	int value;
	string next;
};

struct node {
	int value;
	string address;
	node *next;
	node() { value = -1; next = NULL; }
};

void reverse_linked_list(struct node *head, int k) {
	node *h = head;
	node *cur = head->next;
	node *tail = cur;
	h->next = NULL;
	int cnt = 0;

	while (cur != NULL) {
		node *next = cur->next;
		cur->next = h->next;
		h->next = cur;
		cnt++;

		if (cnt == k) {
			h = tail;
			if (!h) break;

			tail = next;
			h->next = NULL;
			cnt = 0;
		}
		cur = next;
	}

	if (cnt > 0) {
		cur = h->next;
		h->next = NULL;
		while (cur) {
			node *next = cur->next;
			cur->next = h->next;
			h->next = cur;
			cur = next;
		}
	}


}

int main(void) {
	// freopen("../in/1074.in", "r", stdin);
	
	string first_node_address;
	int n, k;
	cin >> first_node_address;
	cin >> n >> k;

	int v;
	string cur_node_address;
	string next_node_address;
	unordered_map<string, Address> nodes;
	for (int i = 0; i < n; i++) {
		cin >> cur_node_address >> v >> next_node_address;
		Address node_address;
		node_address.value = v;
		node_address.next = next_node_address;
		nodes[cur_node_address] = node_address;
	}

	cur_node_address = first_node_address;

	vector<node> nns(n+1);
	struct node *head = &nns[0];
	struct node *p = head;
	int index = 1;
	while (cur_node_address != "-1") {
		struct node *cur = &nns[index];
		if (cur) {
			cur->value = nodes[cur_node_address].value;
			cur->address = cur_node_address;
			cur->next = NULL;
			p->next = cur;
			p = p->next;
		}
		cur_node_address = nodes[cur_node_address].next;
		index++;
	}

	if (k > 1) {
		reverse_linked_list(head, k);
	}

	p = head->next;
	while (p) {
		cout << p->address << " " << p->value << " ";
		if (p->next) 
			cout << p->next->address << endl;
		else 
			cout << -1 << endl;
		p = p->next;
	}

	return 0;
}