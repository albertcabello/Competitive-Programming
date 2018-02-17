#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	double b, s;
	int k = 1;
	while (cin >> b >> s, b || s) {
		double before = min(1.0, s/b);
		if (!(b-1)) {
			cout << "Case " << k << ": :-\\" << endl;
			k++;
			continue;
		}
		double after = min(1.0, (s-1)/(b-1));
		if (before > after) {
			cout << "Case " << k << ": :-(" << endl;
		}
		if (after > before) {
			cout << "Case " << k << ": :-)" << endl;
		}
		if (after == before) {
			cout << "Case " << k << ": :-|" << endl;
		}
		k++;
	}
	return 0;
}
