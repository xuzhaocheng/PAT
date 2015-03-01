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
** 9位数，亿位可以直接读
** 剩下八位分为两个四位，读法基本相同
** 5-8位一般情况下读完加Wan，特殊情况不加Wan：5-8位全0
** 读法：排除前面的0和后面的0，若前面有0且4位不全为0则读0，或者5-8位全0且0-4位不全为0则读0，否则不读0
** 排除前面和后面的0后，若中间有0则读0，多个连续的0只读1个。
*/
int main(void) {
	freopen("../in/1082.in", "r", stdin);
	string digit_w[9] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
	string digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

	vector<int> number;
	long long int nn;
	cin >> nn;
	if (nn < 0) {
		cout << "Fu" << " ";
		nn = -nn;
	}
	while (nn > 0) {
		number.push_back(nn % 10);
		nn /= 10;
	}

	std::reverse(number.begin(), number.end());

	string str;

	bool flag = false;
	if (number.size() == 9) {
		str.append(digit[number[0]]);
		str.append(" Yi ");
		number.erase(number.begin());
	}

	vector<int> n;
	if (number.size() > 4) {
		bool all_zero_flag = true;
		for (int i = 0; i < number.size() - 4; i++) {
			n.push_back(number[i]);
		}
		for (int i = number.size() - 4; i < number.size(); i++)
			if (number[i] != 0)
				all_zero_flag = false;

		vector<int> tmp;
		for (int i = (int)number.size() - 4; i < number.size(); i++)
			tmp.push_back(number[i]);
		number = tmp;

		int end_index = n.size() - 1;
		while (end_index >= 0 && n[end_index] == 0) end_index--;

		int begin_index = 0;
		while (begin_index < n.size() && n[begin_index] == 0) begin_index++;


		if (begin_index > 0 && (begin_index != n.size() || !all_zero_flag)) {
			str.append("ling ");
			flag = true;
		}

		bool zero_flag = false;
		bool output_flag = false;
		for (int i = begin_index; i <= end_index; i++) {
			int index = n.size() - i - 1;
			if (n[i] == 0) {
				if (!zero_flag) {
				 	str.append(digit[n[i]] + " ");
				 	zero_flag = true;
				}
			} else {
				zero_flag = false;
				str.append(digit[n[i]] + " ");
				if (index != 0) 
					str.append(digit_w[index] + " ");
				output_flag = true;
				flag = false;
			}
		}
		
		if (output_flag) {
			str.append("Wan ");
		}

		if (n[n.size() - 1] == 0 && !all_zero_flag && !flag) {
			str.append("ling ");
			flag = true;
		}
	}

	n = number;

	int end_index = n.size() - 1;
	while (end_index >= 0 && n[end_index] == 0) end_index--;

	int begin_index = 0;
	while (begin_index < n.size() && n[begin_index] == 0) begin_index++;

	if (begin_index > 0 && begin_index != n.size() && !flag) {
		str.append("ling ");
	}

	bool zero_flag = false;
	for (int i = begin_index; i <= end_index; i++) {
		int index = n.size() - i - 1;
		if (n[i] == 0) {
			if (!zero_flag) {
			 	str.append("ling");
			 	str.append(" ");
			 	zero_flag = true;
			}
		} else {
			zero_flag = false;
			str.append(digit[n[i]]);
			if (index > 0)
				str.append(" "); 
				str.append(digit_w[index]);
			if (i != end_index)	
				str.append(" ");
		}
	}

	if (str.size() > 0) {
		cout << str[0];
		for (int i = 1; i < (int)str.length() - 1; i++) {
			if (str[i] == ' ' && str[i - 1] == ' ')
				continue;
			cout << str[i];
		}
		if (str.size() > 0 && str[str.length() - 1] != ' ')
			cout << str[str.length() - 1];
	} else {
		cout << "ling";
	}

	return 0;
}