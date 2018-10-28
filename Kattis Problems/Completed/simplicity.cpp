#include<iostream>
#include<map>
using namespace std;

int main() {
	map<char, int> counts;
	int ans = 0;
	char p;
	while (cin >> p) {
		if (counts.find(p) == counts.end()) {
			counts[p] = 1;
		}
		else {
			counts[p] = counts[p] + 1;
		}
	}
	while (counts.size() > 2) {
		int curMin = 100000;
		char min;
		for (auto a : counts) {
			if (a.second < curMin) {
				curMin = a.second;
				min = a.first;
			}
		}
		ans += curMin;
		counts.erase(min);
	}
	cout << ans << endl;
	return 0;
}
