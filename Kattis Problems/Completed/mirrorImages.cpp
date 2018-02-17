#include<iostream>
using namespace std;
int main() {
	int count;
	cin >> count;
	int test = 1;
	while (count--) {
		int l,w;
		cin >> l >> w;
		char arr[l][w];
		string line;
		cin.ignore();
		for (int i = 0; i < w; i++) {
			getline(cin, line);
			for (int j = 0; j < l; j++) {
				arr[i][j] = line[j];
			}
		}
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < w-i; j++) {
				char first = arr[i][j];
				char last = arr[l-1-i][w-1-j];
				arr[i][j] = last;
				arr[l-1-i][w-1-j] = first;
			}
		}
		cout << "Test " << test << endl;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < w; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
		test++;
	}
	return 0;
}
