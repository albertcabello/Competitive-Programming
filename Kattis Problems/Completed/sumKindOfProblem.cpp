#include<iostream>
using namespace std;

int main() {
	int z;
	cin >> z;
	while (z--) {
		int k, n;
		cin >> k >> n;

		cout << k << " " << (n*(n+1))/2 << " " << (n*n) << " " << n*(n+1) << endl;
	}
	return 0;
}
