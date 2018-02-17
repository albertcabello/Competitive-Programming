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
			return S[find(u)];
		}
};


int main() {
	UnionFind uf(10);
	uf.join(1,2);
	uf.join(1,4);
	uf.join(3,2);
	uf.join(3,4);
	cout << uf.sizeOfSet(1) << endl;
}

