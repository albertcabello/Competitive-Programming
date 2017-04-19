#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<map>
using namespace std;
vector<pair<int,int> > getNeighbors(int x, int y) {
	vector<pair<int, int> > neighbors;
	if ((x+1 >= 0 && x+1 < 8) && (y+2 >= 0 && y+2 < 8)) {
		neighbors.push_back(make_pair(x+1 , y+2));
	}
	if ((x-1 >= 0 && x-1 < 8) && (y+2 >= 0 && y+2 < 8)) {
		neighbors.push_back(make_pair(x-1, y+2));
	}
	if ((x-1 >= 0 && x-1 < 8) && (y-2 >= 0 && y-2 < 8)) {
		neighbors.push_back(make_pair(x-1, y-2));
	}
	if ((x+1 >= 0 && x+1 < 8) && (y-2 >= 0 && y-2 < 8)) {
		neighbors.push_back(make_pair(x+1, y-2));
	}
	if ((x+2 >= 0 && x+2 < 8) && (y+1 >= 0 && y+1 < 8)) {
		neighbors.push_back(make_pair(x+2, y+1));
	}
	if ((x+2 >= 0 && x+2 < 8) && (y-1 >= 0 && y-1 < 8)) {
		neighbors.push_back(make_pair(x+2, y-1));
	}
	if ((x-2 >= 0 && x-2 < 8) && (y+1 >= 0 && y+1 < 8)) {
		neighbors.push_back(make_pair(x-2, y+1));
	}
	if ((x-2 >= 0 && x-2 < 8) && (y-1 >= 0 && y-1 < 8)) {
		neighbors.push_back(make_pair(x-2, y-1));
	}
	return neighbors;
}
struct location {
	int row;
	int col;
	int dist;
};
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
		int dcol = trans[dest[0]];
		int drow = stoi(dest.substr(1));
		queue<location> q;
		location front;
		front.row = 8-srow;
		front.col = scol;
		front.dist = 0;
		q.push(front);
		int count = 0;
		board[8-srow][scol] = "S";
		while (q.size()) {
			location current = q.front();
			q.pop();
			if (current.row == 8-drow && current.col == dcol) {
				cout << "To get from " << source << " to " << dest << " takes " << current.dist << " knight moves." << endl;
				break;
			}
			for (pair<int, int> n : getNeighbors(current.row, current.col)) {
				if (board[n.first][n.second] == ".") {
					board[n.first][n.second] = to_string(current.dist);
					location next;
					next.row = n.first;
					next.col = n.second;
					next.dist = current.dist+1;
					q.push(next);
				}
			}
		}
	}

	return 0;
}
