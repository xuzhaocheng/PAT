#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <stack>
#include "stdlib.h"

using namespace std;

/*
** 就是已知中序先序求后序
*/

struct node {
	int v;
	struct node *lchild;
	struct node *rchild;
	node(int vv) { v = vv; lchild = rchild = NULL; }
};

int find_root_index(int root_value, vector<int> &inorder, int s, int e) {
	for (int i = s; i <= e; i++)
		if (inorder[i] == root_value) return i;
	return -1;
}

struct node* build_tree(vector<int> &preorder, int offset, vector<int> &inorder, int s, int e) {
	if (s > e || offset >= preorder.size())	{
		return NULL;
	}
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->v = preorder[offset];

	int root_index = find_root_index(root->v, inorder, s, e);
	root->lchild = build_tree(preorder, offset + 1, inorder, s, root_index - 1);
	root->rchild = build_tree(preorder, offset + root_index - s + 1, inorder, root_index + 1, e);
	return root;
}

void traverse(struct node* root, vector<int> &res) {
	if (root) {
		traverse(root->lchild, res);
		traverse(root->rchild, res);
		res.push_back(root->v);
	}
}

int main(void) {
	freopen("../../in/1086.in", "r", stdin);
	int n;
	vector<int> preorder;
	vector<int> inorder;
	
	cin >> n;

	string op;
	int node;
	stack<int> s;
	for (int i = 0; i < 2 * n; i++) {
		cin >> op;
		if (op == "Push") {
			cin >> node;
			preorder.push_back(node);
			s.push(node);
		} else {
			inorder.push_back(s.top());
			s.pop();
		}
	}

	struct node *root = build_tree(preorder, 0, inorder, 0, inorder.size() - 1);

	vector<int> res;
	traverse(root, res);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1)
			cout << " ";
	}
	cout << endl;
	return 0;
}
