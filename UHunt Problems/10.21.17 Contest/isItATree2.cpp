#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
	int n1, n2;
	int k = 1;
	map<int, vector<int> > adjList;
	vector<vector<int> > adjMatrix;
	while (cin >> n1 >> n2) {
		if (n1 == -1 && n2 == -1) {
			return 0;
		}
		if (n1 == 0 && n2 == 0) {
			for (int i = 0; i < nodeCount; i++) {
				if (adjMatrix[i][i] < INF) {
					cout << "Case " << k << " is not a tree." << endl;
				}
				else {
					cout << "Case " << k << " is a tree." << endl;
				}
			}
		}

