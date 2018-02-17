#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;
int main() {
	int N;
	int C;
	cin >> N;
	while (N--) {
		unordered_map<string, int> catCounts;
		unordered_map<string, int> minimumKeys;
		unordered_map<string, string> keyBelong;
		cin >> C;
		while (C--) {
			string cat;
			int keys, minKeys;
			cin >> cat >> keys >> minKeys;
			minimumKeys[cat] = minKeys;
			while (keys--) {
				string key;
				cin >> key;
				keyBelong[key] = cat;
			}
		}
		string line;
		while (getline(cin, line)) {
			cout << "line" << endl;
			stringstream ss;
			ss.str(line);
			string word;
			ss >> word;
			while (ss >> word) {
				catCounts[keyBelong[word]] += 1;
			}
		}
		for (auto it : catCounts) {
			cout << it.first << endl;
		}
	}
	return 0;
}
