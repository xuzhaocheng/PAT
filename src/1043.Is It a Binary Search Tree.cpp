/*
** 递归查找
** BST可以根据根节点的大小来将数组划分为左子树和右子树，具体方法为：
** 1) 因为是先序序列，所以数组第一个元素为根，向后找到第一个大于等于根的节点idx
** 2) 检查是否是BST，继续向后移动指针，如果后面所有的元素都大于等于根节点，那么这棵树为BST。
** 3) 根据找到的第一个大于等于根的节点，将数组分为两部分（[begin+1, idx-1],[idx, end])继续查找
** 4) 直到begin >= end递归结束。
** 同理可以检查是否是Minor_BST。
** 由于每次递归先递归左子树、右子树，所以在递归函数中访问了左右子树之后在将根节点加入结果集，就能构造出后序序列。
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

vector<int> result;

int findGreater(const vector<int> &preorder, int begin, int end) {
	int res = -1;
	for (int i = begin + 1; i <= end; i++) {
		if (preorder[begin] <= preorder[i] && res == -1) {
			res = i;
		} else if (preorder[begin] > preorder[i] && res != -1) {
			return -1;
		}
	}
	if (res != -1)
		return res;
	return end + 1;
}

int findLess(const vector<int> &preorder, int begin, int end) {
	int res = -1;
	for (int i = begin + 1; i <= end; i++) {
		if (preorder[begin] > preorder[i] && res == -1) {
			res = i;
		} else if (preorder[begin] <= preorder[i] && res != -1) {
			return -1;
		}
	}
	if (res != -1)
		return res;
	return end + 1;
}

bool dfs(const vector<int> &preorder, int begin, int end) {
	cout << "begin:" << begin << ", end:" << end << endl;
	if (begin > end) return true;
	if (begin == end) {
		result.push_back(preorder[begin]);
		return true;
	}

	int greater = findGreater(preorder, begin, end);
	if (greater == -1)	return false;

	bool res = dfs(preorder, begin + 1, greater - 1);
	if (!res)	return res;
	res = dfs(preorder, greater , end);

	result.push_back(preorder[begin]);

	return res;
}

bool dfs_minor(const vector<int> &preorder, int begin, int end) {
	if (begin > end) return true;
	if (begin == end) {
		result.push_back(preorder[begin]);
		return true;
	}

	int less = findLess(preorder, begin, end);
	if (less == -1)	return false;

	bool res = dfs_minor(preorder, begin + 1, less - 1);
	if (!res)	return res;
	res = dfs_minor(preorder, less , end);

	result.push_back(preorder[begin]);

	return res;
}


void print() {
	cout << "YES" << endl;
	if (!result.empty()) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
			if (i != result.size() - 1)
				cout << " ";
		}
		cout << endl;
	}
}

int main(void) {
	freopen("../in/1043.in", "r", stdin);
	int n;
	cin >> n;
	vector<int> preorder(n);
	for (int i = 0; i < n; i++) 
		cin >> preorder[i];

	bool res = dfs(preorder, 0, n - 1);
	if (res) {
		print();
	} else {
		result.clear();
		res = dfs_minor(preorder, 0, n - 1);
		if (res)
			print();
		else 
			cout << "NO" << endl;
	}

	return 0;
}