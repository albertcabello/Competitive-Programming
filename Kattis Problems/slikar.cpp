#include<iostream>
#include<set>
#include<iomanip>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[36m"
#define RESET "\033[0m"
vector<vector<int> > field;
struct location {
	int row;
	int col;
	int dist;
	char cont;
};
vector<pair<int, int> > getNeighbors(int x, int y) {
	vector<pair<int, int> > ans;
	//Above
	if (x-1 >= 0) {
		ans.push_back(make_pair(x-1, y));
	}
	//Below
	if (x+1 < field.size()) {
		ans.push_back(make_pair(x+1, y));
	}
	//Right
	if (y+1 < field[x].size()) {
		ans.push_back(make_pair(x, y+1));
	}
	//Left 
	if (y-1 >= 0) {
		ans.push_back(make_pair(x, y-1));
	}
	return ans;
}
void print() {
	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field[i].size(); j++) {
			switch (field[i][j]) {
			case -1: cout << GREEN << setw(5) << field[i][j] << RESET; break;
			case 75: cout << GREEN << setw(5) << field[i][j] << RESET; break;
			case 80: cout << RED << setw(5) << field[i][j] << RESET; break;
			case 90: cout << GREEN << setw(5) << field[i][j] << RESET; break;
			default: cout << BLUE << setw(5) << field[i][j] << RESET; break;
			}
		}
		cout << endl;
	}
}
void flood(queue<location> q) {
	set<pair<int, int> > visited;
	while(q.size()) {
		//Check if dam is surrounded, quit early
		location current = q.front();
		q.pop();
		int tile = field[current.row][current.col];
		if (tile == 75 || tile == 90 || tile == 80 || tile < current.dist) continue;
		field[current.row][current.col] = current.dist;
		for (pair<int, int> n : getNeighbors(current.row, current.col)) {
			if(visited.find(n) == visited.end()) {
				visited.insert(n);
				location next;
				next.row = n.first;
				next.col = n.second;
				next.dist = current.dist+1;
				q.push(next);
			}
		}
	}
}	
int main() {
	ios::sync_with_stdio(false);
	clock_t start;
	double duration;
	int rows, columns;
	cin >> rows >> columns;
	cin.ignore();
	location root;
	queue<location> willFlood;
	for (int i = 0; i < rows; i++) {
		string row;
		getline(cin, row);
		vector<int> vecRow;
		for (int j = 0; j < columns; j++) {
			location node;
			if (row[j] == 'S') {
				root.row = i;
				root.col = j;
				root.dist = 0;
				vecRow.push_back(75);
				continue;
			}
			if (row[j] == '*') {
				location toFlood;
				toFlood.row = i;
				toFlood.col = j;
				toFlood.dist = 0;
				willFlood.push(toFlood);
				vecRow.push_back(0);
				continue;
			}
			if (row[j] == 'X') {
				vecRow.push_back(80);
				continue;
			}
			if (row[j] == 'D') {
				vecRow.push_back(90);
				continue;
			}
			vecRow.push_back(60);
		}
		field.push_back(vecRow);
	}
	flood(willFlood);
	duration = (clock() - start)/(double)CLOCKS_PER_SEC;
	cout << duration << endl;
	queue<location > q;
	vector<pair<int, int> > visited;
	q.push(root);
	//BFS is implemented, need to add check to see if the neighbor is flooded 
	while (q.size()) {
		location current = q.front();
		q.pop();
		if (field[current.row][current.col] == 80) {
			continue;
		}
		if (field[current.row][current.col] == 90) {
			cout << current.dist << endl;
			break;
			duration = (clock() - start)/(double)CLOCKS_PER_SEC;
			cout << "End: " << duration << endl;;
			return 0;
		}
		field[current.row][current.col] = -1;
		for (pair<int, int> n : getNeighbors(current.row, current.col)) {
//			if (find(visited.begin(), visited.end(), n) == visited.end()) {
			if (field[n.first][n.second] != -1) {
				location next;
				next.dist = current.dist + 1;
				next.row = n.first;
				next.col = n.second;
				if (next.dist < field[next.row][next.col] || field[next.row][next.col] == 90) {
					q.push(next);
				}
			}
		}
	}
	duration = (clock() - start)/(double)CLOCKS_PER_SEC;
	cout << "End: " << duration << endl;
	cout << "KAKTUS" << endl;
	return 0;
}
