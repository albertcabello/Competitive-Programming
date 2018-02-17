#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct node {
	int x, y, distFromSrc, weight;
	bool operator>(const struct node& other) const {
		return distFromSrc > other.distFromSrc;
	}
} node;

vector<node> getNeighbors(node n , vector<vector<node> > maze) {
	vector<node> ans;
	int x, y;
	x = n.x; y=n.y;
	if (x-1 >= 0) {
		ans.push_back(maze[x-1][y]);
	}
	if (x+1 < maze.size()) {
		ans.push_back(maze[x+1][y]);
	}
	if (y+1 < maze[x].size()) {
		ans.push_back(maze[x][y+1]);
	}
	if (y-1 >= 0) {
		ans.push_back(maze[x][y-1]);
	}
	return ans;
}


int main() {
	int N;
	cin >> N;
	while (N--) {
		vector<vector<node> > graph;
		priority_queue<node, vector<node>, greater<node> > pq;
		int rows, cols;
		cin >> rows >> cols;
		for (int i = 0; i < rows; i++) {
			vector<node> line;
			for (int j = 0; j < cols; j++) {
				int num;
				cin >> num;
				if (i == 0 && j == 0) {
					node n = {i, j, 0, num};
					line.push_back(n);
					pq.push(n);
					continue;
				}
				node n = {i,j, INT_MAX, num};
				line.push_back(n);
			}
			graph.push_back(line);
		}
		while (pq.size()) {
			node u = pq.top(); 
			pq.pop();
			if (u.x == rows-1 && u.y == cols-1) {
				cout << u.distFromSrc << endl;
				break;
			}
			for (node v : getNeighbors(u, graph)) {
				int alt = u.distFromSrc + v.weight;
				if (alt < v.distFromSrc) {
					v.distFromSrc = alt;
					pq.push(v);
				}
			}
		}
//		for (auto b : graph) {
//			for (auto a : b) {
//				cout << a.distFromSrc << " ";
//			}
//			cout << endl;
//		}
	}
	return 0;
}
