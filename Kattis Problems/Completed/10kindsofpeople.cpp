#include<iostream>
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

};

int main() {
	int r, c;
	cin >> r >> c;
	vector<int> nums(r*c, 0);
	UnionFind uf(r*c);
	for (int i = 0; i < r*c; i++) {
		char num;
		cin >> num;
		nums[i] = (num-'0');
		//Do the join operations now
		//Join as we take in inputs, neighbors are the places to the immediate left 
		//and "above"
		if ((i % c) != 0 && nums[i] == nums[i-1]) {
			uf.join(i, i-1);
		}
		if ((i-c) >= 0 && nums[i] == nums[i-c]) {
			uf.join(i, i-c);
		}
	}
	int count;
	cin >> count;
	while (count--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//Convert pair of coordinates (one based) to a single integer
		int i = (x1-1)*c+(y1-1);
		int j = (x2-1)*c+(y2-1);
		if (uf.isJoint(i,j)) {
			if (nums[i] == 1) {
				cout << "decimal" << endl;
			}
			else {
				cout << "binary" << endl;
			}
		}
		else {
			cout << "neither" << endl;
		}
	} 
	return 0;
}
