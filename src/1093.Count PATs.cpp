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
	// freopen("../in/1093.in", "r", stdin);
	string pat;
	cin >> pat;
	long long p_count, pa_count, pat_count;
	pat_count = p_count = pa_count = 0;
	for (int i = 0; i < pat.size(); i++) {
		if (pat[i] == 'P') {
			p_count++;
		} else if (pat[i] == 'A') {
			pa_count += p_count;
		} else if (pat[i] == 'T') {
			pat_count += pa_count;
		}
	}
	cout << pat_count % 1000000007 << endl;
	return 0;
}