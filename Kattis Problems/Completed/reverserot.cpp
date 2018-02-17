#include<iostream>
using namespace std;

int main() {
	string list = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
	int shift;
	cin >> shift;
	while (shift) {
		string word;
		cin >> word;
		for (string::reverse_iterator rit = word.rbegin(); rit != word.rend(); ++rit) {
			int perChar = shift;
			int num = *rit;
			if (num == 95 && perChar) {
				perChar--;
				num = 27;
			}
			if (num == 46 && perChar) {
				perChar--;
				num = 28;
			}
			if (num > 28 && perChar) {
				num -= 65;
			}
			num += perChar;
			cout << list[num % 28];
		}
		cout << endl;
		cin >> shift;
	}
	return 0;
}
