#include<iostream>
#include<vector>
using namespace std;
class UnionFind {
	private: 
		int N; 
		vector<int> DS;
		vector<int> S;
	public:
		UnionFind(int n) {
			N = n+1;
			DS.assign(N, -1);
			S.assign(N, 1);
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

		void join(int u, int v) {
			if (isJoint(u,v)) return; //U and V are already joined
			u = find(u);
			v = find(v);
			if (DS[u] < DS[v]) {
				DS[v] = u;
				S[u] += S[v];
			}
			else if (DS[v] < DS[u]) {
				DS[u] = v;
				S[v] += S[u];
			}
			else {
				DS[v] = u;
				S[u] += S[v];
				DS[u]--;
			}
		}

		int sizeOfSet(int u) {
			return S[u];
		}
};


int main() {
	int N, Q;
	cin >> N >> Q;
	UnionFind uf(N);
	while (Q--) {
		char action;
		cin >> action;
		int num1, num2;
		cin >> num1 >> num2;
		if (action == '?') {
			if (uf.isJoint(num1,num2)) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
		if (action == '=') {
			uf.join(num1, num2);
		}
	}
	return 0;
}

