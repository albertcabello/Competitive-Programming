#include<iostream>
#include<queue>
#include<set>
using namespace std;
typedef struct location {
	int row, col;
	char cont;
} location;

set<pair<int, int> > visited;

vector<pair<int, int> > getNeighbors(int x, int y, vector<vector<char> > field) {
        vector<pair<int, int> > ans;
        //Above
        if (x-1 >= 0 && field[x-1][y] == '@') {
                ans.push_back(make_pair(x-1, y));
        }
        //Below
        if (x+1 < field.size() && field[x+1][y] == '@') {
                ans.push_back(make_pair(x+1, y));
        }
        //Right
        if (y+1 < field[x].size() && field[x][y+1] == '@') {
                ans.push_back(make_pair(x, y+1));
        }
        //Left
        if (y-1 >= 0 && field[x][y-1] == '@') {
                ans.push_back(make_pair(x, y-1));
        }
	//Up-right
	if (x-1 >= 0 && y+1 < field[x-1].size() && field[x-1][y+1] == '@') {
		ans.push_back({x-1,y+1});
	}
	//Up-left
	if (x-1 >= 0 && y-1 >= 0 && field[x-1][y-1] == '@') {
		ans.push_back({x-1,y-1});
	}
	//Down-right
	if (x+1 < field.size() && y+1 < field[x+1].size() && field[x+1][y+1] == '@') {
		ans.push_back({x+1, y+1});
	}
	//Down-left
	if (x+1 < field.size() && y-1 < field[x+1].size() && field[x+1][y-1] == '@') {
		ans.push_back({x+1,y-1});
	}
      	return ans;
}

int countBFS(location start, vector<vector<char> > field) {
	int ans = 0;
	queue<location> q;
	q.push(start);
	while (q.size()) {
		location current = q.front();
		q.pop();
		if (visited.find({current.row, current.col}) == visited.end()) {
			ans++;
		}
		for (pair<int, int> n : getNeighbors(current.row, current.col, field)) {
			if (visited.find(n) == visited.end()) {
				visited.insert(n);
				location next;
				next.row = n.first;
				next.col = n.second;
				q.push(next);
			}
		}
	}
	return ans;
}

int main() {
	int r, c;
	while (cin >> r >> c, r || c) {
		vector<vector<char> > field(r, vector<char> (c));
		vector<location> oil;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				char s;
				cin >> s;
				field[i][j] = s;
				if (s == '@') {
					location n;
					n.row = i; n.col = j; n.cont = '@';
					oil.push_back(n);
				}
			}
		}
		int ans = 0;
		for (location a: oil) {
			ans += countBFS(a, field);
		}
		cout << ans << endl;
		field.clear();
		visited.clear();
	}
	return 0;
}
