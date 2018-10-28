#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#define INF 10000001
using namespace std;

vector<int> go(vector<vector<pair<int, int> > > adjList, int s) {
	vector<int> dist (adjList.size(), INF);
	dist[s] = 0;
	priority_queue<int> pq;
	pq.push(s);
	while (pq.size()) {
		int u = pq.top();
		pq.pop();
		for (pair<int, int> v : adjList[u]) {
			int alt = dist[u] + v.second;
			if (alt < dist[v.first]) {
				dist[v.first] = alt;
				pq.push(v.first);
			}
		}
	}
	return dist;
}

int main() {
	int n, m, q, s;
	while (cin >> n >> m >> q >> s, n || m || q || s) { 
		vector<int> nodes;
		vector<vector<pair<int, int> > > adjList(n);
		for (int i = 0; i < n; i++) {
			nodes.push_back(i);
		}
		while (m--) { 
			int u, v, w;
			cin >> u >> v >> w;
			adjList[u].push_back({v,w});
		}
		vector<int> dists = go(adjList, s);
		while (q--) { 
			int i;
			cin >> i;
			if (dists[i] == INF) {
				cout << "Impossible" << endl;
			}
			else {
				cout << dists[i] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
