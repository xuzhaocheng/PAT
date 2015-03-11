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
	freopen("../in/1058.in", "r", stdin);
	
	int g1, g2, s1, s2, k1, k2;
	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);

	k1 += k2;
	s1 += k1 / 29;
	k1 %= 29;

	s1 += s2;
	g1 += s1 / 17;
	s1 %= 17;

	g1 += g2;

	printf("%d.%d.%d\n", g1, s1, k1);

	return 0;
}