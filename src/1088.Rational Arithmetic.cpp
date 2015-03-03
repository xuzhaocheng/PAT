#include <iostream>
#include <math.h>

using namespace std;

int gcd(long int a, long int b) {
	if (a == 0 || b == 0) return 1;
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a < b) {
		long int tmp = a;
		a = b;
		b = tmp;
	}
	long int r = a % b;
	while (r > 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}



void output_num(long int a, long int b) {
	if (a < 0) cout << "(-";
	
	if (a == 0) cout << a;
	else if (b == 0) cout << "Inf";
	else {
		if (abs(a / b) > 0) {
			cout << abs(a) / b;
			if (a % b != 0) cout << " ";
		}
		if (a % b != 0) cout << abs(a) % b << "/" << b;

	}
	
	if (a < 0) cout << ")";
}



int main(void) {
//	freopen("d:\\Rational Arithmetic.in", "r", stdin);
	long int a, b, c, d;
	scanf("%ld/%ld", &a, &b);
	scanf("%ld/%ld", &c, &d);
	
	int gcd_ab = gcd(a, b);
	int gcd_cd = gcd(c, d);
	
	a = a / gcd_ab;
	b = b / gcd_ab;
	
	c = c / gcd_cd;
	d = d / gcd_cd;
	
	long c1 = a / b;
	long a1 = a % b;
	long c2 = c / d;
	long a2 = c % d;


	output_num(a, b);
	cout << " + ";
	output_num(c, d);
	cout << " = ";
	long aa = a * d + c * b;
	long bb = b * d;
	int gcd_aabb = gcd(aa, bb);
	aa /= gcd_aabb;
	bb /= gcd_aabb;
	output_num(aa, bb);
	cout << endl;

	output_num(a, b);
	cout << " - ";
	output_num(c, d);
	cout << " = ";
	aa = a * d - c * b;
	bb = b * d;
	gcd_aabb = gcd(aa, bb);
	aa /= gcd_aabb;
	bb /= gcd_aabb;
	output_num(aa, bb);
	cout << endl;

	output_num(a, b);
	cout << " * ";
	output_num(c, d);
	cout << " = ";
	aa = a * c;
	bb = b * d;
	gcd_aabb = gcd(aa, bb);
	aa /= gcd_aabb;
	bb /= gcd_aabb;
	output_num(aa, bb);
	cout << endl;

	output_num(a, b);
	cout << " / ";
	output_num(c, d);
	cout << " = ";
	if (c == 0)
		cout << "Inf";
	else {
		aa = a * d;
		bb = b * c;
		gcd_aabb = gcd(aa, bb);
		aa /= gcd_aabb;
		bb /= gcd_aabb;

		if (aa * bb < 0) {
			aa = -abs(aa);
			bb = abs(bb);
		}

		if (aa < 0 && bb < 0) {
			aa = -aa, bb = -bb;
		}

		output_num(aa, bb);

	}
	cout << endl;

	return 0;
}

