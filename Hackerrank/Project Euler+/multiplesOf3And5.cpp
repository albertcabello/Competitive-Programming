#include<iostream>
using namespace std;
int main() {
	int Z, N;
	cin >> Z;
	while (Z--) {
		cin >> N;
		long long n3 = (N-1)/3;
		long long n5 = (N-1)/5;
		long long n15 = (N-1)/15;
		long long sum3 = 3 * (n3 * (n3 + 1) ) / 2;
		long long sum5 = 5 * (n5 * (n5 + 1) ) / 2;
		long long sum15 = 15 * (n15 * (n15 + 1) ) / 2;
		cout << sum3 + sum5 - sum15 << endl;
	}
	return 0;
}
