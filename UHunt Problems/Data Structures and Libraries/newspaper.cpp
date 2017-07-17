#include<iostream>
#include<iomanip>
#include<map>
#include<vector>
using namespace std;
int main() {
	int count;
	cin >> count;
	while (count--) {
		int sum = 0;
		int num;
		cin >> num;
		map<char, int> values;
		while (num--) {
			char ch;
			cin >> ch;
			int val;
			cin >> val;
			values[ch] = val;
		}
		cin >> num;
		cin.ignore();
		while (num--) {
			string line;
			getline(cin, line);
			for (int i = 0; i < line.length(); i++) {
				sum += values[line[i]];
			}
		}
		cout << fixed << setprecision(2) <<  sum / 100.0 << "$" << endl;
	}
	return 0;
}
