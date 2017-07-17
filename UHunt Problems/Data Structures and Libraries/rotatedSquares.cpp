#include<iostream>
#include<vector>
using namespace std;
int main() {
	int b, s;
	while (cin >> b >> s && b != 0 && s != 0) {
		vector<vector<char>> big;
		vector<vector<char>> small;
		for (int i = 0; i < b; i++) {
			string line;
			cin >> line;
			vector<char> lineVec;
			for (auto s : line) {
				lineVec.push_back(s);
			}
			big.push_back(lineVec);
		}
		for (int i = 0; i < s; i++) {
			string line;
			cin >> line;
			vector<char> lineVec;
			for (auto s : line) {
				lineVec.push_back(s);
			}
			small.push_back(lineVec);
		}
		vector<vector<char>> s90;
		vector<vector<char>> s180;
		vector<vector<char>> s270;
//		for (auto vec : big) {
//			for (auto ch : vec) {
//				cout << ch;
//			}
//			cout << endl;
//		}
//		for (auto vec: small) {
//			for (auto ch : vec) {
//				cout << ch;
//			}
//			cout << endl;
//		}
	}
	return 0;
}
