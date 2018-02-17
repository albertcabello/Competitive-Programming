#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	while (cin >> N, N) {
		vector<vector<int> > adjList;
		for (int i = 0; i < N; i++) {
			vector<int> line;
			int count;
			cin >> count;
			for (int j = 0; j < count; j++) {
				int num;
				cin >> num;
				line.push_back(num);
			}
			adjList.push_back(line);
		}
		for (auto a : adjList) {
			for (auto b : a) {
				cout << b << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
