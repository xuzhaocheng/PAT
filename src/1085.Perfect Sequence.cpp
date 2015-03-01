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
** 从长度为0开始
** 如果 nums[j] <= nums[i] * p
** 那么就可以搜索更长的长度，j++
** 否则再增大nums[j]也无济于事，i++
*/
int main(void) {
	freopen("../in/1085.in", "r", stdin);
	int n;
	long long int p;

	cin >> n;
	cin >> p;

	vector<long long int> nums;
	
	long long int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
	}

	std::sort(nums.begin(), nums.end());

	int i, j;
	i = j = 0;
	int max_len = 0;
	while (j < n) {
		if (nums[j] <= nums[i] * p) {
			if (max_len < j - i + 1)
				max_len = j - i + 1;
			j++;
		} else {
			i++;
		}
	}
	
	cout << max_len;
	return 0;
}