#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main() {
	int Z;
	cin >> Z;
	vector<int> a;
	while (Z--) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	int ans = 0;
	while (a.size()) {
		ans++;
		vector<int> indicesToDelete;
		int cur = a[0];
		indicesToDelete.push_back(0);
		for (int i = 0; i < a.size(); i++) {
//			set<int> visited;
			if (a[i] + 1 == cur) {
				indicesToDelete.insert(indicesToDelete.begin(), i);
//				visited.insert(a[i]);
				cur--;
			}
		}
		for (auto i : indicesToDelete) {
			a.erase(a.begin() + i);
		}
	}
	cout << ans << endl;


	return 0;
}


