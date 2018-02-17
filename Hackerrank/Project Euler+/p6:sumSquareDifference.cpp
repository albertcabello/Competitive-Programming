#include<iostream>
using namespace std;
int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		long long N;
		cin >> N;
		long long s1 = N * (N + 1) * (2*N + 1) / 6;
		long long s2 = N * (N + 1) / 2;
		cout << s2 * s2 - s1 << endl;
	}
	return 0;
}
