#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		int p, q, d;
		cin >> p >> q >> d;
		if (d % gcd(p,q)) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}
