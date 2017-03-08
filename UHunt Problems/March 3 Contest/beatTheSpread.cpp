#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int x, y;
		cin >> x >> y;
		if (y > x) {
			cout << "impossible" << endl;
			continue;
		}
		int a1, a2, b1, b2;
		a1 = (x + y) / 2;
		b1 = (x - y) / 2;
		a2 = (x - y) / 2;
		b2 = (x + y) / 2;
		if (a1 + b1 == x && a1 - b1 == y) {
			cout << max(a1, b1) << " " << min(a1,b1) << endl;
		}
		if (a2 + b2 == x  && a2 - b2 == y) {
			cout << max(a2, b2) << " " << min(a2, b2) << endl;
		}	
		else {
			cout << "impossible" << endl;
		}	
	}
	return 0;
}
