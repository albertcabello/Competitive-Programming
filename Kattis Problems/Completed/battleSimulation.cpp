#include<iostream>
using namespace std;
int main() {
	string line;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		string sub = line.substr(i,3);
		if (sub.find('R') != string::npos && sub.find('B') != string::npos && sub.find('L') != string::npos) {
			cout << 'C';
			i+=2;
			continue;
		}
		switch (line[i]) {
		case 'R':
			cout << 'S';
			break;
		case 'B':
			cout << 'K';
			break;
		case 'L':
			cout << 'H';
			break;
		default:
			break;
		}
	}
	return 0;
}

