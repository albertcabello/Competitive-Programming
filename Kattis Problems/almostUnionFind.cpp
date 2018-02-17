#include<iostream>
#include<set>
#include<vector>
using namespace std;
class UnionFind {
	private: 
		int N; 
		vector<int> DS;
		vector<int> S;
		vector<int> sums;
	public:
		UnionFind(int n) {
			N = n+1;
			DS.assign(N, -1);
			S.assign(N, 1);
			sums.assign(N, 0);
			for (int i = 0; i < N; i++) {
				sums[i] = i;
			}
		}

		int find(int u) {
			if (DS[u] < 0) { //If less than zero, that means u is a root of a tree
				return u;
			}
			return DS[u] = find(DS[u]);
		}

		bool isJoint(int u, int v) {
			return find(u) == find(v);
		}

		void move(int u, int v) {
			DS[u] = -1;
			join(u, v);
		}

		void join(int u, int v) {
			if (isJoint(u,v)) return; //U and V are already joined
			u = find(u);
			v = find(v);
			if (DS[u] < DS[v]) {
				DS[v] = u;
				S[u] += S[v];
				sums[u] += sums[v];
				sums[v] = 0;
			}
			else if (DS[v] < DS[u]) {
				DS[u] = v;
				S[v] += S[u];
				sums[v] += sums[u];
				sums[u] = 0;
			}
			else {
				DS[v] = u;
				S[u] += S[v];
				sums[u] += sums[v];
				sums[v] = 0;
				DS[u]--;
			}
		}

		int sizeOfSet(int u) {
			return S[find(u)];
		}

		void printSets() {
			vector<set<int> > ans (N, set<int>());
			for (int i = 0; i < DS.size(); i++) {
				ans[find(i)].insert(i);
			}
			for (int i = 0; i < ans.size(); i++) {
				cout << "Set: ";
				for (auto it : ans[i]) {
					cout << it << ", ";
				}
				cout << "Total Sum: " << sums[i] << endl;
			}
		}
		void printDS() {
			for (auto a : DS) {
				cout << a << " ";
			}
			cout << endl;
		}
};


int main() {
//	int n, m;
//	while (cin >> n >> m) {
//		UnionFind uf(n);
//		int command, num1, num2;
//		for (int i = 0; i < m; i++) {
//			cin >> command >> num1;
//			if (command == 1) {
//				cin >> num2;
//				uf.join(num1,num2);
//			}
//			if (command == 2) {
//				cin >> num2;
//				uf.move(num1,num2);
//			}
//			if (command == 3) {
//				uf.printSets();
//				cout << "Size: " << uf.sizeOfSet(4) << endl;
//			}
//		}
//	}
	UnionFind uf(5);
	uf.join(1,4);
	uf.join(4,3);
	uf.move(2,5);
	uf.printDS();
	uf.printSets();
	cout << "Change" << endl;
	uf.move(2,1);
	uf.printDS();
	uf.printSets();
	return 0;
}
