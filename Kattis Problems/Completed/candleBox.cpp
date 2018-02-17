#include<iostream>
using namespace std;
int main() {
	int d, r, t;
	cin >> d >> r >> t;
	int ritaCandles, theoCandles;
	ritaCandles = theoCandles = 0;
	for (int i = 4; i < 34; i++) {
		if (i-d < 3) {
			ritaCandles += i;
			continue;
		}
		ritaCandles += i;
		theoCandles += i-d;
		if (ritaCandles + theoCandles == r + t) {
			cout << r - ritaCandles << endl;
		}
	}
	return 0;
}
		
