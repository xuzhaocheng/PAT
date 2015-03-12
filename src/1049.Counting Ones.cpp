/*
** 对于某一个位上的总的1的个数有如下规律
** 1) 如果这个位上的数字为0，比如101的十位
** 那么这个位上的1的个数就等于它的高位的数字乘以这个位的权（这里是十位，乘以10），结果为10（分别为10..19）
** 2) 如果这个位上的数字为1，比如111
** 那么这个位上的1的个数就等于它的高位的数字乘以这个位的权，再加上他的低位的数字再加1，结果为10+1+1（分别为10..19, 110, 111)
** 3) 如果这个位上的数字大于1，比如121
** 那么这个位上的1的个数就等于它的(高位的数字+1)乘以这个位的权，结果为20（分别为10..19, 110..119)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <set>
#include "stdlib.h"

using namespace std;

int oneCounter(int n) {
	int cnt = 0;
	int digit = 1;
	int higher, lower, cur;

	while (n / digit != 0) {
		higher = n / (digit * 10);
		lower = n - (n / digit) * digit;
		cur = (n / digit) % 10;
		if (cur == 0) {
			cnt += higher * digit;
		} else if (cur == 1) {
			cnt += higher * digit + lower + 1;
		} else {
			cnt += (higher + 1)* digit;
		}
		digit *= 10;
	}

	return cnt;
}

int main(void) {
	// freopen("../in/1049.in", "r", stdin);
	
	int n;
	cin >> n;
	
	cout << oneCounter(n) << endl;
	return 0;
}