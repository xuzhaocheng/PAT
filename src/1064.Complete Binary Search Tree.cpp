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
** 根据左孩子的个数，判断当前结点处于当前数组区间的第几个。
*/
void fillNode(vector<int> &nums, vector<int> &childNumber,
 			  vector<int> &levelOrderTraverse, int i, int begin, int end) {

	// i不是一个结点
	if (i >= nums.size())	return;

	// i没有左孩子，肯定也没有右孩子，此时begin == end
	if (2 * i + 1 >= nums.size()) {
		levelOrderTraverse[i] = nums[begin];
		return;
	}

	// 求出当前结点左孩子的个数
	int leftChildNumber = childNumber[2 * i + 1];

	// 这个元素就为当前区间的第leftChildNumber个元素
	levelOrderTraverse[i] = nums[begin + leftChildNumber];

	// 计算左孩子对应的nums数组中的值
	fillNode(nums, childNumber, levelOrderTraverse, 2 * i + 1, begin, begin + leftChildNumber - 1);

	// 计算右孩子对应的nums数组中的值
	fillNode(nums, childNumber, levelOrderTraverse, 2 * i + 2, begin + leftChildNumber + 1, end);
}

/*
** 求某个结点下所有孩子的总数
*/
int childNodeNumber(vector<int> &nums, vector<int> &childNumber, int i) {
	if (i >= nums.size()) return 0;

	int n = childNodeNumber(nums, childNumber, 2 * i + 1);
	n += childNodeNumber(nums, childNumber, 2 * i + 2);

	childNumber[i] = n + 1;
	return childNumber[i];
}

int main(void) {
	// freopen("../in/1064.in", "r", stdin);
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	std::sort(nums.begin(), nums.end());

	vector<int> levelOrderTraverse(n);
	vector<int> childNumber(n, 0);
	
	childNodeNumber(nums, childNumber, 0);
	fillNode(nums, childNumber, levelOrderTraverse, 0, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << levelOrderTraverse[i];
		if (i != n - 1)
			cout << " ";
	}
	
	return 0;
}