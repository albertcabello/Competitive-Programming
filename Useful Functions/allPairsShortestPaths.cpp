#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1000000000
using namespace std;
int main() {
    int n, m, q;
    while (cin >> n >> m >> q, n || m || q) {
        vector<vector<int> > adjMatrix(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
            adjMatrix[i][i] = 0;
        for (int i = 0; i < m; i++) {
            int v1,v2,w;
            cin >> v1 >> v2 >> w;
            adjMatrix[v1][v2] = min(adjMatrix[v1][v2], w);
        }
	//Set each node to have a distance to itself of zero
	//Floyd warshall algorithm
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j] && adjMatrix[i][k] != INF && adjMatrix[k][j] != INF)
                        adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
	//Queries
        while (q--) {
            int v1, v2;
            cin >> v1 >> v2;
            int ans = adjMatrix[v1][v2];
	    for (int i = 0; i < n; i++) {
	    	if (adjMatrix[v1][i] != INF && adjMatrix[i][v2] != INF && adjMatrix[i][i] < 0) {
			ans = -INF;
			break;
		}
	    }
            if (ans == INF) {
                cout << "Impossible" << endl;
            }
            else if (ans == -INF) {
                cout << "-Infinity" << endl;
            }
            else {
                cout << ans << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
