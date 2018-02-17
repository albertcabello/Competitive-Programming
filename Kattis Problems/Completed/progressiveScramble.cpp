#include<iostream>
#include<vector>
using namespace std;
int main() {
	int count;
	cin >> count;
	cin.ignore();
	string alph = " abcdefghijklmnopqrstuvwxyz";
	while (count--) {
		string line;
		getline(cin, line);
		char command = line[0];
//		line = line.substr(2,string::npos);
		if (command == 'e') {
			line = line.substr(2,string::npos);
			int sum = 0;
			for (int i = 0; i < line.length(); i++) {
				char cur = line[i];
				if (cur == ' ') {
//					ans.append(1, alph[sum % 27]);
					cout << alph[sum % 27];
					continue;
				}
				sum += (int)cur - 96;
//				ans.append(1, alph[sum % 27]);
				cout << alph[sum % 27];
			}
			cout << endl;
		}
		else {
			line = line.substr(2,string::npos);
			int sum = 0;
			string ans;
			for (int i = 0; i < line.length(); i++) {
				char cur = line[i];
				int num;
				if (cur == ' ') {
					num = 0;
				}
				else {
					num = (int)cur - 96;
				}
				int x = 27*i+num - sum;
				sum +=x;
				cout << alph[x % 27];
			}
			cout << endl;
		}
	}
	return 0;
}

