#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[i+1]) {
			cout << s << endl;
			s.erase(i,i+2);
			i-=2;
			cout << s << endl;
		}
	}
	if (s == "") {
		cout << "1" << endl;
	}
	else {
		cout << s << endl;
	}
	return 0;
}
