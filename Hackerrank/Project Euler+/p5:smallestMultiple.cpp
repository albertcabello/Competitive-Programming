#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n == 2) {
			cout << 2 << endl;
			continue;
		}
		int a = 1;
		for (int i = 2; i <= n; i++) {
			a = lcm(a,i);
		}
		cout << a << endl;
	}
	return 0;
}
