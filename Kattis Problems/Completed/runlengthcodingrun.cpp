#include<iostream>
#include<string>
using namespace std;
string encode(string x) {
	string ans = "";
	int countChar = 0;
	char curChar = x[0];
	for (int i = 0; i <= x.size(); i++) {
		if (curChar != x[i]) {
			ans += curChar;
			ans += to_string(countChar);
			curChar = x[i];
			countChar = 0;
		}
		countChar++;
	} 
	return ans;
}

string decode(string x) {
	string ans = "";
	for (int i = 0; i < x.size(); i+=2) {
		int rep = x[i+1] - '0';
		while (rep--) {
			ans += x[i];
		}
	}
	return ans;
}
		

int main() {
	char command;
	string input;
	cin >> command >> input;

	if (command == 'E') {
		cout << encode(input) << endl;
	}
	else {
		cout << decode(input) << endl;
	}
	return 0;
}
