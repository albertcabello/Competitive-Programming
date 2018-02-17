#include<iostream>
using namespace std;
int main() {
	char num, slash, den;
	while (cin >> num >> slash >> den, num - '0' && den - '0') {
		int numerator = num - '0';
		int denominator = den - '0';
		int count = 0;
		for (int x = den; x <= 2*den; x++) {
			for (int y = den; y <= 2*den; y++) {
				if (1/x + 1/y == 1/den) {
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
