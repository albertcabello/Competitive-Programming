#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<set>
#include<utility>
using namespace std;
struct vertex {
	int row;
	int col;
	int dist;
	int weight;
	char val;
	vertex *prev;
};
struct comp {
	bool operator () (vertex lhs, vertex rhs) {
		return lhs.dist < rhs.dist;
	}
};
vector<vector<vertex> > board;
vector<vertex> getNeighbors(vertex n) {
	int row = n.row;
	int col = n.col;
	vector<vertex> ans;
	if (row-1 >= 0) {
		if (board[row-1][col].val != 'E' || board[row-1][col].val != 'S') {
			ans.push_back(board[row-1][col]);
		}
	}
	if (row+1 < board.size()) {
		if (board[row+1][col].val != 'E' || board[row+1][col].val != 'S') {
			ans.push_back(board[row+1][col]);
		}
	}
	if (col+1 < board[row].size()) {
		if (board[row][col+1].val != 'E' || board[row][col+1].val != 'S') {
			ans.push_back(board[row][col+1]);
		}
	}
	if (col-1 >= 0) {
		if (board[row][col-1].val != 'E' || board[row][col-1].val != 'S') {
			ans.push_back(board[row][col-1]);
		}
	}
	return ans;
}
void printBoard() {
	for (auto a : board) {
		for (auto b : a ) {
			cout << b.val << " ";
		}
		cout << endl;
	}
}
int main() {
	int count = 0;
	int z;
	cin >> z;
	while(z--) {
		board.clear();
		int row, col;
		cin >> row >> col;
		vertex source;
		for (int i = 0; i < row; i++) {
			vector<vertex> vecRow;
			int j = 0;
			for (int j = 0; j < col; j++) {
				char line;
				cin >> line;
				vertex node;
				node.row = i;
				node.col = j;
				node.dist = INT_MAX;
				node.val = line;
				if (line == 'X') {
					node.weight = INT_MAX;
				}
				else if (line == 'E') {
					node.weight = 0;
				}
				else if (line == 'S') {
					source = node;
					source.dist = 0;
					source.weight = INT_MAX;
					vecRow.push_back(source);
					continue;
				}
				else {
					node.weight = line - '0';
				}
				vecRow.push_back(node);
			}
			board.push_back(vecRow);
		}
		//board populated		
//		printBoard();
		priority_queue<vertex, vector<vertex>, comp> q;
		q.push(source);
//		cout << source.row << " " << source.col << endl;
		bool broke = false;
		while (q.size()) {
			vertex u = q.top();
			q.pop();
			if (count++ < 20) {
				cout << " " << u.row << " " << u.col << " " << u.weight << " " <<  u.dist << endl;
			}
			if (board[u.row][u.col].val == 'E') {
				cout << "WE HIT THE E" << endl;
				cout << u.dist << endl;
				continue;
			}
			for (vertex v : getNeighbors(u)) {
				int alt = u.dist + v.weight;
				cout << "Alt: " << alt << " dist u " << u.dist << " v.weight " << v.weight << endl;
				if (alt < v.dist) {
					v.dist = alt;
					v.prev = &u;
					q.push(v);
				}
			}
		}
		if(!broke) {
			cout << "none" << endl;
		}
	}
	return 0;
}
