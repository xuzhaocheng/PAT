#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool is_sorted(vector<int> &nums, int b, int l){
	for (int i = b + 1; i < b + l; i++) {
		if (nums[i] < nums[i-1])
			return false;
	}
	return true;
}

bool merge_sort_check(vector<int> &nums, int n) {
	int i = 0;
	while (i < nums.size()) {
		int len = i + n > nums.size() ? nums.size() - i : n;
		if (!is_sorted(nums, i, len))
			return false;
		i += n;
	}
	return true;
}

int main(void) {
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<int> partial_sorted_nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];	
	}

	for (int i = 0; i < n; i++)
		cin >> partial_sorted_nums[i];

	int i;
	int index;
	for (i = 1; i < n; i++) {
		if (partial_sorted_nums[i] < partial_sorted_nums[i-1]) {
			index = i;
			break;
		}
	}

	while (i < n && nums[i] == partial_sorted_nums[i]) i++;
	if (i == n) {
		cout << "Insertion Sort" << endl;
		i = 0;
		while (i < index && partial_sorted_nums[i] < partial_sorted_nums[index]) i++;
		int tmp = partial_sorted_nums[index];
		for (int j = index; j > i; j--) {
			partial_sorted_nums[j] = partial_sorted_nums[j-1];
		}
		partial_sorted_nums[i] = tmp;
	} else {
		cout << "Merge Sort" << endl;
		int m = 2;
		while (m <= nums.size()) {
			if (!merge_sort_check(partial_sorted_nums, m)) 
				break;
			m = m * 2;
		}

		i = 0;
		while (i < n) {
			vector<int>::iterator end = i + m > nums.size() ? partial_sorted_nums.end() : partial_sorted_nums.begin() + i + m;
			std::sort(partial_sorted_nums.begin() + i, end);
			i += m;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << partial_sorted_nums[i];
		if (n != i + 1) cout << " ";
	}
	cout << endl;

	return 0;
}

