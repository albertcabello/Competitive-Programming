#include<iostream>
#include<sstream>
#include<list>
using namespace std;
int main() {
	string line;
	while(cin >> line) {
		list<char> toPrint;
		list<char>::iterator pos = toPrint.begin();
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '[') {
				pos = toPrint.begin();
				continue;
			}
			else if (line[i] == ']') {
				pos = toPrint.end();
				continue;
			}
			toPrint.insert(pos, line[i]);
		}
		for (auto a : toPrint) {
			cout << a;
		}
		cout << endl;
	}
	return 0;
}

