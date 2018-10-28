#include<iostream>
using namespace std;
int gcd(int x, int y) {
	if (y == 0) 
		return x;
	else 
		return gcd(y, x % y);
}

int lcm(int x, int y) {
	return (x*y) / gcd(x, y);
}

int main() {
	int p,q,s;
	cin >> p >> q >> s;
	if (lcm(p,q) <= s) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}

