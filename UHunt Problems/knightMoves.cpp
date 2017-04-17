#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	string source, dest;
	while (cin >> source >> dest) {
		vector<vector<string> > board = {  {".", ".", ".", ".", ".", ".", ".", "."},
						{".", ".", ".", ".", ".", ".", ".", "."},
						{".", ".", ".", ".", ".", ".", ".", "."},
						{".", ".", ".", ".", ".", ".", ".", "."},
						{".", ".", ".", ".", ".", ".", ".", "."},
						{".", ".", ".", ".", ".", ".", ".", "."},
						{".", ".", ".", ".", ".", ".", ".", "."},
						{".", ".", ".", ".", ".", ".", ".", "."} };
		map<char, int> trans;
		trans['a'] = 0;
		trans['b'] = 1;
		trans['c'] = 2;
		trans['d'] = 3;
		trans['e'] = 4;
		trans['f'] = 5;
		trans['g'] = 6;
		trans['h'] = 7;
		int scol = trans[source[0]];
		int srow = stoi(source.substr(1));
		cout << scol << " " << srow << endl;
		board[8-srow][scol] = "X";
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
