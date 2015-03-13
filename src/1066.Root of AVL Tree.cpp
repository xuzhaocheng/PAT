/*
** http://www.cnblogs.com/baochuan/archive/2012/10/16/2716641.html
** AVL树的基本操作
** 长久了还真马上写不出来，多练加深理解！
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

struct AVLNode {
	int data;
	int height;
	AVLNode *lchild, *rchild;
	AVLNode(int d) : data(d), height(0), lchild(NULL), rchild(NULL) {}
};

int getHeight(AVLNode *node) {
	if (node) return node->height;
	return -1;
}

bool isBalanced(AVLNode *parent) {
	return abs(getHeight(parent->lchild) - getHeight(parent->rchild)) < 2;
}


AVLNode *rotateLL(AVLNode *parent) {
	AVLNode *child = parent->lchild;
	parent->lchild = child->rchild;
	child->rchild = parent;

	parent->height = max(getHeight(parent->lchild), getHeight(parent->rchild)) + 1;
	child->height = max(getHeight(child->lchild), getHeight(child->rchild)) + 1;
	return child;
}

AVLNode *rotateRR(AVLNode *parent) {
	AVLNode *child = parent->rchild;
	parent->rchild = child->lchild;
	child->lchild = parent;

	parent->height = max(getHeight(parent->lchild), getHeight(parent->rchild)) + 1;
	child->height = max(getHeight(child->lchild), getHeight(child->rchild)) + 1;
	return child;
}

AVLNode *rotateLR(AVLNode *parent) {
	AVLNode *child = parent->lchild;
	parent->lchild = rotateRR(child);
	return rotateLL(parent);
}

AVLNode *rotateRL(AVLNode *parent) {
	AVLNode *child = parent->rchild;
	parent->rchild = rotateLL(child);
	return rotateRR(parent);
}


AVLNode *insertNode(AVLNode *root, int value) {
	if (root) {
		if (value > root->data) {
			root->rchild = insertNode(root->rchild, value);
			if (!isBalanced(root)) {
				if (value > root->rchild->data) {	// RR
					root = rotateRR(root);
				} else {
					root = rotateRL(root);		//RL
				}
			}
		} else {
			root->lchild = insertNode(root->lchild, value);
			if (!isBalanced(root)) {
				if (value < root->lchild->data) {
					root = rotateLL(root);
				} else {
					root = rotateLR(root);
				}
			}
		}
	} else {
		root = new AVLNode(value);
	}

	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	return root;
}

int main(void) {
	freopen("../in/1066.in", "r", stdin);
	
	int n;
	cin >> n;

	AVLNode *root = NULL;
	int v;
	for (int i = 0; i < n; i++) {
		cin >> v;
		root = insertNode(root, v);
	}

	cout << root->data << endl;
	return 0;
}