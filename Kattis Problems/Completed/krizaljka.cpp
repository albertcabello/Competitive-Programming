#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string first, second;
	cin >> first >> second;
	vector<vector<char> > array(second.length(), vector<char>(first.length(), '.'));

	
	int row, col;  //Row for the first word, column for the second;
	for (int i = 0; i < first.length(); i++) {
		int index = second.find(first[i]);
		if (index != string::npos) {
			row = index;
			col = i;
			break;
		}
	}

	for (int i = 0; i < first.length(); i++) {
		array[row][i] = first[i];
	}

	for (int i = 0; i < second.length(); i++) {
		array[i][col] = second[i];
	}


	for (auto a : array) {
		for (auto b : a) {
			cout << b;
		}
		cout << endl;
	}

	return 0;
}
