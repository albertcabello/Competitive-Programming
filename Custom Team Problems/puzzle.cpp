#include<iostream>
#include<vector>
using namespace std;
vector<vector<char> > board;
vector<vector<char> > piece;
void printBP() {
	cout << "BOARD: " << endl;
	for (auto a : board) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
	cout << "PIECE:" << endl;
	for (auto a : piece) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
}	
int main() {
	int n;
	cin >> n;
	while(n--) {
		board.clear();
		piece.clear();
		int hb, wb;
		int fpx, fpy;
		int fxx, fxy;
		cin >> hb >> wb;
		string line;
		getline(cin, line);
		for (int i = 0; i < hb; i++) {
			vector<char> vecRow;
			for (int j = 0; j < wb; j++) {
				char ch;
				cin >> ch;
				if (ch == '.' && !fpx && !fpy) {
					fpy = board.size(); fpx = vecRow.size();
				}
				vecRow.push_back(ch);
			}
			board.push_back(vecRow);
		}
		int hp, wp;
		cin >> hp >> wp;
		for (int i = 0; i < hp; i++) {
			vector<char> vecRow;
			for (int j = 0; j < wp; j++) {
				char ch;
				cin >> ch;
				if (ch == 'X' && !fxx && !fxy) {
					fxy = piece.size(); fxx = vecRow.size();
				}
				vecRow.push_back(ch);
			}
			piece.push_back(vecRow);
		}
		//Board and piece populated
		bool broken = false;
		for (int i = fpy; i < fpy+hp && !broken; i++) {
			for (int j = fpx-fxx; j < fpx+wp-fxx && !broken; j++) {
				if (board[i][j] == piece[i-fpy][j-fpx-fxx]) {
					broken = true;
				}
			}
		}
		if (!broken) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
		fpy = fpx = fxx = fxy = 0;
			
	}
	return 0;
}

