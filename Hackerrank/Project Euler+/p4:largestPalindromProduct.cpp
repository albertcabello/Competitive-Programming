#include<iostream>
#include<algorithm>
using namespace std;
int rev(int num) {
	int rev = 0, rem;
	while (num) {
		rem = num % 10;
		rev = rev*10 + rem;
		num /= 10;
	}
	return rev;
}
int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		int max;
		cin >> max;
		int ans = 0;
		for (int i = 0; i < 1000; i++) {
			for (int j = i; j < 1000; j++) {
				if (rev(i*j) == i*j && i*j < max) {
					if (i*j > ans) {
						ans = i*j;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
