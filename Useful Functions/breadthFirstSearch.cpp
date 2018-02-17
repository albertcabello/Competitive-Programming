/*
 * BFS Template
*/
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
typedef struct location {
	int x,y,dist;
	bool visited = 0;
} location;
vector<vector<location> > grid;
vector<pair<int, int> > getNeighbors(int x, int y) {
	vector<pair<int, int> > ans;
	//Above neighbor
	if (x - 1 >= 0)
		ans.push_back({x-1,y});
	//Below neighbor
	if (x+1 < grid.size())
		ans.push_back({x+1,y});
	//Left neighbor
	if (y-1 >= 0) 
		ans.push_back({x,y-1});
	//Right neighbor
	if (y+1 < grid[x].size()) 
		ans.push_back({x,y+1});
	return ans;
}

int main() {
	int r,c; //Row count and column count
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		vector<location> row;
		for (int j = 0; j < c; j++) {
			char p;
			cin >> p;
			location loc;
			loc.x = i;
			loc.y = j;
			loc.dist = 0;
			row.push_back(loc);
		}
		grid.push_back(row);
	}
	//End taking in of input and begin BFS
	queue<location> q;
	q.push(grid[0][0]); //Change root to whatever, currently top left corner
	while (q.size()) {
		location cur = q.front();
		q.pop();
		if (cur.x == r-1 && cur.y == c-1) { //Change stop condition to whatever, currently goes to bottom right corner
			cout << "Found the bottom right corner in " << cur.dist << " steps" << endl;
			break;
		}
		for (pair<int, int> neigh : getNeighbors(cur.x, cur.y)) {
			location next = grid[neigh.first][neigh.second];
			if (!next.visited) { //Add to this any extra conditions
				next.dist = cur.dist + 1;
				q.push(next);
			}
		}
	}
	return 0;
}


