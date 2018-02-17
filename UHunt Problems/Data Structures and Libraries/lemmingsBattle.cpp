#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
	int N;
	cin >> N;
	while (N--) {
		int b, sg, sb;
		cin >> b >> sg >> sb;
		multiset<int, greater<int> > greenArmy, blueArmy;
		while (sg--) {
			int t;
			cin >> t;
			greenArmy.insert(t);
		}
		while (sb--) {
			int t;
			cin >> t;
			blueArmy.insert(t);
		}
		while (greenArmy.size() && blueArmy.size()) {
			vector<int> greenRound, blueRound;
			for (int i = 0; i < b && blueArmy.size() && greenArmy.size(); i++) {
				greenRound.push_back(*(greenArmy.begin()));
				blueRound.push_back(*(blueArmy.begin()));
				greenArmy.erase(greenArmy.begin());
				blueArmy.erase(blueArmy.begin());
			}
			for (int i = 0; i < greenRound.size(); i++) {
				int diff = greenRound[i] - blueRound[i];
				if (diff > 0) {
					greenArmy.insert(diff);
				}
				if (diff < 0) {
					blueArmy.insert(diff * -1);
				}
			}
		}
		if (greenArmy.size()) {
			cout << "green wins" << endl;
			for (auto it : greenArmy) {
				cout << it << endl;
			}
			if (N > 0) {
				cout << endl;
			}
		}
		else if (blueArmy.size()) {
			cout << "blue wins" << endl;
			for (auto it : blueArmy) {
				cout << it << endl;
			}
			if (N > 0) {
				cout << endl;
			}
		}
		else {
			cout << "green and blue died" << endl;
			if (N > 0) {
				cout << endl;
			}
		}

	}
	return 0;
}
