#include<iostream>
using namespace std;
int main() {
	int count, max, students;
	cin >> count;
	for (int i = 0; i < count; i++) {
		max = 0;
		cin >> students;
		for (int j = 0; j < students; j++) {
			int temp;
			cin >> temp;
			if (temp > max) {
				max = temp;
			}
		}
		cout << "Case " << i+1 << ": " << max << endl;
	}
	return 0;
}
