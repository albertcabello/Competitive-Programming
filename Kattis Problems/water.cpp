#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
typedef struct edge edge;

struct edge {
	int capacity, flow, source, sink;
	edge *reverse;
};

int maxFlow(vector<edge> adj[], int source, int sink) {
	int flow = 0;
	return flow;
}

int main() {
	int n, p, k;
	cin >> n >> p >> k;
	vector<edge> adj[n]; //Adjaceny list
	//START INITIAL CONFIGURATION
	for (int i = 0; i < n; i++) {
		adj[i] = NULL;
	}
	for (int i = 0; i < p; i++) { //Build the adjacency list
		int a,b,c;
		cin >> a >> b >> c;
		edge e;
		e.source = a;
		e.sink = b;
		e.flow = 0;
		e.capacity = c;
		adj[a].push_back(e);
	}
	maxFlow(adj, 1, 2); //1 is always source and 2 is sink
	for (int i = 1; i <= p; i++) {
		for (auto a : adj[i]) {
			cout << "There is a pipe from " << a.source << " to " << a.sink << " with capacity " << a.capacity << endl;
		}
	}
	//END INITIAL CONFIGURATION

	return 0;
}
