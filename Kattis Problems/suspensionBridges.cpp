#include<iostream>
#include<cmath>
using namespace std;

double mround(double val) {
	return (val * 100000000.0) / 100000000.0;
}


int main() {
	double a, s, d, l, r, m;
	cin >> d >> s;
	l = 0;
	r = 1e5;
	m = (l+r)/2;
	a = m;
	while (mround(a+s) != mround(a * cosh(d/(2*a)))) {
		cout << "Trying " << m << endl;
		if (mround(a+s) - mround(a*cosh(d/(2*a))) > 0) {
			l += 1000;
		}
		else {
			r -= 1000;
		}
		m = (l+r)/2;
		cout << 2 * a * sinh(d / (2* a)) << endl;
		a = m;
	}

}
