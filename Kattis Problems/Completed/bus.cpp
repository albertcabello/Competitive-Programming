#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	while (N--) {
		int k; 
		cin >> k;
		int n = 0;
		for (int i = 0; i < k; i++) {
			n = (n + .5) * 2;
		}
		cout << n << endl;
	}
	return 0;
}
			
