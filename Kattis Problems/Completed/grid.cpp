/*
 * BFS Template
*/
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
typedef struct location {
	int x,y,dist, num;
	bool visited = 0;
} location;
vector<vector<location> > grid;
vector<pair<int, int> > getNeighbors(int x, int y, int dist) {
	vector<pair<int, int> > ans;
	if (!dist) return ans;
	//Above neighbor
	if (x - dist >= 0)
		ans.push_back({x-dist,y});
	//Below neighbor
	if (x+dist < grid.size())
		ans.push_back({x+dist,y});
	//Left neighbor
	if (y-dist >= 0) 
		ans.push_back({x,y-dist});
	//Right neighbor
	if (y+dist < grid[x].size()) 
		ans.push_back({x,y+dist});
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
			loc.num = p -'0';
			row.push_back(loc);
		}
		grid.push_back(row);
	}
	//End taking in of input and begin BFS
	queue<location> q;
	/*
	if (grid[0][0].num == 0) {
		cout << -1 << endl;
		return 0;
	}
	*/
	q.push(grid[0][0]); //Change root to whatever, currently top left corner
	while (q.size()) {
		location cur = q.front();
		q.pop();
		if (cur.x == r-1 && cur.y == c-1) { //Change stop condition to whatever, currently goes to bottom right corner
			cout << cur.dist << endl;
			return 0;
		}
		for (pair<int, int> neigh : getNeighbors(cur.x, cur.y, cur.num)) {
			location next = grid[neigh.first][neigh.second];
			if (!next.visited) { //Add to this any extra conditions
				grid[neigh.first][neigh.second].dist = cur.dist + 1;
				grid[neigh.first][neigh.second].visited = 1;
				q.push(grid[neigh.first][neigh.second]);
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
