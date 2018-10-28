#include<iostream>
#include<map>
using namespace std;
int main() {
	map<string, pair<bool, int> > defs;
	string command;
	while (cin >> command) {
		if (command == "def") {
			string word;
			int num;
			cin >> word >> num;
			defs[word] = {1,num}
		}
	}
	return 0;
}
