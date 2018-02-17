#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 2000000
using namespace std;
int main() {
	int n, h, l;
	cin >> n >> h >> l;

	vector<int> dists(n, INF);
	vector<vector<int> > adjList (n);
	queue<int> q;
	//Horror list
	for (int i = 0; i < h; i++) {
		int num;
		cin >> num;
		dists[num] = 0;
		q.push(num);
	}

	//Pairings
	for (int i = 0; i < l; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	//BFS
	while (q.size()) {
		int cur = q.front();
		q.pop();
		for (int neigh : adjList[cur]) {
			if (dists[cur] + 1 < dists[neigh]) {
				dists[neigh] = dists[cur] + 1;
				q.push(neigh);
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (dists[i] > dists[max]) {
			max = i;
		}
	}

	cout << max << endl;
	return 0;
}
