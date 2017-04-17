#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int s, p;
		cin >> s >> p;
		priority_queue<pair<int, ii>, vector< pair<int, ii> > > qu;
		qu.push(iii(s, ii(1, s)));
		for (int j = 0; j < p - 1; j++) {	
			iii threep = qu.top();
			qu.pop();
			int mid;
			if (threep.first % 2) { 
				mid = threep.first / 2;
			}
			else {
				mid = (threep.first+ 1) / 2;
			}
			int low = threep.second.first;
			int high = threep.second.second;
			qu.push(iii(mid-low, ii(low, mid-1)));
			qu.push(iii(high-mid, ii(mid+1, high)));
		}
		iii kth = qu.top();
		qu.pop();
		int mid;
		if (kth.first % 2 == 0) { 
			mid = kth.first / 2;
		}
		else {
			mid = (kth.first+ 1) / 2;
		}
		int low = kth.second.first;
		int high = kth.second.second;
		int ls = mid - low;
		int rs = high - mid;
		cout << "Case #" << i+1 << " " << max(ls, rs) << " " << min(ls, rs) << endl;
	}	
	return 0;
}
