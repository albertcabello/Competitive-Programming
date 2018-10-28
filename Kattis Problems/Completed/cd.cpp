#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m, n || m) {
		int ans = 0;
		int *a = (int *)malloc((int)1e10);
		while (n--) {
			int t;
			cin >> t;
			a[t]++;
		}
		while (m--) {
			int t;
			cin >> t;
			if (++a[t] >= 2) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
