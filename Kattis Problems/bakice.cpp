#include<iostream>
#include<map>
#include<queue>
#include<utility>
#include<vector>
#include<set>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[36m"
#define RESET "\033[0m"
using namespace std;
typedef struct location {
	int x,y,dist;
	char type;
	bool visited = 0;
	bool seat = 0;
	bool seatTaken = 0;
	pair<int, int> parent;
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
int flood(queue<location> q) {
	set<pair<int, int> > exploded;
	int explosionCount = 0;
	while (q.size()) {
		location cur = q.front();
		q.pop();
		vector<pair<int, int> > neighbors = getNeighbors(cur.x, cur.y);
		//To prevent a person going to two seats, stop if you find one
		bool seatRun = 0;
		for (pair<int, int> n : neighbors)
			if (grid[n.first][n.second].seat) 
				seatRun = 1;
		//BFS
		for (pair<int, int> n : neighbors) {
			location next = grid[n.first][n.second];
			//If the distance of next node is greater than the current dist + 1, change dist
			//and push to queue if there was no neighboring seat
			if (next.dist > cur.dist + 1 && !seatRun) {
				grid[n.first][n.second].dist = cur.dist + 1;
				grid[n.first][n.second].parent = cur.parent;
				q.push(grid[n.first][n.second]);

			}
			//Same as above except no queue push because there's a neighboring seat
			if (next.dist > cur.dist + 1 && seatRun) {
				grid[n.first][n.second].dist = cur.dist + 1;
				grid[n.first][n.second].parent = cur.parent;
			}
			//If the next seat has the same dist, but it came from a different person, there's an explosion so add it
			//to the explosion set.  Why a set?  If you keep a counter and 3 people go to same seat, counter goes up twice for 
			//the same explosion
			if (next.dist == cur.dist + 1 && next.seat)
				if (next.parent != cur.parent)
					exploded.insert({next.x,next.y});
		}
	}
	return exploded.size();
}

int main() {
	int r,c; //Row count and column count
	cin >> r >> c;
	queue<location> q;
	vector<location> people;
	for (int i = 0; i < r; i++) {
		vector<location> row;
		for (int j = 0; j < c; j++) {
			char p;
			cin >> p;
			location loc;
			loc.x = i;
			loc.y = j;
			loc.type = '.';
			loc.dist = 9;
			if (p == 'L') {
				loc.seat = 1;
			}
			if (p == 'X') {
				loc.visited = 1;
				loc.parent = {i,j};
				loc.dist = 0;
				loc.type = 'X';
				people.push_back(loc);
				q.push(loc);
			}
			row.push_back(loc);
		}
		grid.push_back(row);
	}
	cout << flood(q) << endl;
	
	for (auto a : grid) {
		for (auto b : a) {
			if (b.seat)
				cout << RED << b.dist << RESET << " ";
			else if (b.type == 'X')  
				cout << GREEN << b.dist << RESET << " ";
			else 
				cout << b.dist << " ";
		}
		cout << endl;
	} 
	
	return 0;
}
			

