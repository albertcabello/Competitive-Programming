#include<iostream>
#include<set>
#include<math.h>
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
	int n, h, l;
	cin >> n >> h >> l;
	int H = n+5; //Head of the horror movie list
	UnionFind uf(n+10); //Number of movies plus the head of the horror movies plus leeway
	set<int> horrorList; //ID of horror movie list
	for (int i = 0; i < h; i++) { //Join horror list to horror head 
		int num;
		cin >> num;
		horrorList.insert(num);
		uf.join(num, H);
	}
	for (int i = 0; i < l; i++) { //Join all movies that are similar
		int a, b;
		 cin >> a >> b;
		 uf.join(a, b);
	}
	int bestID = H;
	for (int i = 0; i < n; i++) {
		if (!uf.isJoint(H, i)) { //i is not a horror movie
			if (!uf.isJoint(H, bestID)) { //bestID is also not a horror movie
				int tempBestID = min(bestID, i); //Set to minimum id then
				if (horrorList.find(tempBestID) == horrorList.end()) { //Not a horror movie, no override
					bestID = tempBestID;
				}
			}
			else { //bestID is not a horror movie, i gets priority
				int tempBestID = i;
				if (horrorList.find(tempBestID) == horrorList.end()) { //Not a horror movie, no override
					bestID = tempBestID;
				}
			}
		}
		else { //i is a horror movie
			if (uf.isJoint(H, bestID)) { //bestID is horror movie
				int tempBestID = min(bestID, i); //Lower gets priority
				if (horrorList.find(tempBestID) == horrorList.end()) { //Not a horror movie, no override
					bestID = tempBestID;
				}
			}
		}
	}
	cout << bestID << endl;
	return 0;

}


