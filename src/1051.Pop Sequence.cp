/*
** 维护一个栈和一个队列
** 对于序列中的每个元素，先从栈顶找，如果找到，则这个元素合法
** 否则，找这个元素在队列里的位置，如果存在，则将其前面的所有元素入栈，然后检查栈大小是否合法。
** 如果不存在，则非法。
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

int main(void) {
	// freopen("../in/1051.in", "r", stdin);
	
	int m, n, k;
	cin >> m >> n >> k;
	
	vector<int> nums(n);
	for (int i = 1; i <= n; i++) {
		nums[i-1] = i;
	}

	int x;
	for (int i = 0; i < k; i++) {
		vector<int> left = nums;
		stack<int> s;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			cin >> x;

			// 已经不合法，不用检查后面的元素
			if (!flag)	continue;

			// 在栈顶，肯定合法
			if (!s.empty() && s.top() == x) {
				s.pop();
			} else {
				// 将其前面的所有元素入栈
				while (left.size() > 0 && left[0] != x) {
					s.push(left[0]);
					left.erase(left.begin());
				}

				// 如果存在，则size大于0
				if (left.size() > 0 && left[0] == x) {
					// 删掉这个元素
					left.erase(left.begin());
					// 检查栈大小是否合法，因为这里x没有入栈，所以是>=
					if (s.size() >= m)	flag = false;
				} else if (left.size() == 0) {
					// 没有找到，说明在栈中，非法
					flag = false;
				}
			}
		}
		if (flag)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}

	return 0;
}