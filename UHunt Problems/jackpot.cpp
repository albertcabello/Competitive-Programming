#include<iostream>
using namespace std;
int main() {
	int max = 0;
	int cur = 0;
	int count;
	cin >> count;
	while (count != 0) {
		for (int i = 0; i < count; i++) {
			int num;
			cin >> num;
			cur += num;
			if (cur < 0) {
				cur = 0;
			}
			if (cur > max) max = cur;

		}
		if (max != 0) {
			cout << "The maximum winning streak is " << max << "." << endl;
		}
		else {
			cout << "Losing streak." << endl;
		}
		max = cur = 0;
		cin >> count;
	}
	return 0;
}

